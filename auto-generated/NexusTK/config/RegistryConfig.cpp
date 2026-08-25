// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000N4
// Source by-file doc: by-file/RegistryConfig.md
// UID:0000BW | by-class/RegistryConfig.md | Completion:92 | Confidence:94
#include "RegistryConfig.h"

// UID:000329 | by-memory/0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor.md | Completion:88 | Confidence:91
// Compiler-generated RegistryConfig scalar deleting destructor wrapper.
// Emitted code for this range is covered by [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md) and [UID:00032F][0x0048e780-0x0048e85a.RegistryConfigDestructor](by-memory/0x0048e780-0x0048e85a.RegistryConfigDestructor.md).

// UID:00032F | by-memory/0x0048e780-0x0048e85a.RegistryConfigDestructor.md | Completion:88 | Confidence:90
RegistryConfig::~RegistryConfig()
{
    delete m_midiTrackPaths;
    m_midiTrackPaths = 0;

    free(m_logDataText);
    m_logDataText = 0;

    m_musicFolderPath.Release();
    m_blockListenNames.Clear();
    m_startupLauncherId.Release();

    for (int i = 0; i < 20; ++i)
        m_profileStringSlots[i].Release();

    m_configScratchString.Release();
    m_serverEntries.ReleaseOwnedBuffers();
    m_serverEntries.DestroyRecords();

    g_pConfig = 0;
}

// UID:00030U | by-memory/0x0048e860-0x0048e94f.RegistryConfigLoadOrInitialize.md | Completion:88 | Confidence:90
void RegistryConfig::LoadOrInitialize()
{
    m_alternateServerEndpointActive = false;

    InitializeDefaults();
    if (!LoadFromRegistry())
        InitializeDefaults();

    GetMemoryMan();
    m_startupReady = 1;

    wchar_t commandLine[0x400];
    wcscpy_s(commandLine, _countof(commandLine), GetCommandLineW());

    wchar_t *argumentStart = wcschr(commandLine, L'"');
    if (argumentStart)
        argumentStart = wcschr(argumentStart + 1, L'"');
    else
        argumentStart = wcschr(commandLine, L' ');

    if (!argumentStart)
        return;

    wchar_t *context = 0;
    int tokenCount = 0;
    wchar_t *token = wcstok_s(argumentStart + 1, L" ", &context);
    if (!token) {
        m_startupReady = 1;
        return;
    }

    while (++tokenCount < 8) {
        token = wcstok_s(0, L" ", &context);
        if (!token) {
            m_startupReady = 1;
            return;
        }
    }
}

// UID:00030W | by-memory/0x0048ebc0-0x0048eecf.RegistryConfigInitializeUserDataDefaults.md | Completion:89 | Confidence:91
void RegistryConfig::InitializeUserDataDefaults()
{
    for (int i = 0; i < 10; ++i)
        wcscpy_s(m_profileTextSlots[i], _countof(m_profileTextSlots[i]),
                 g_pLanguageMan->GetLocalizedString(67 + i));

    for (int i = 0; i < 10; ++i)
        wcscpy_s(m_legacyShortcutText[i], _countof(m_legacyShortcutText[i]), L"");

    wcscpy_s(m_selectedProfileName, _countof(m_selectedProfileName), L"");

    for (int i = 0; i < 20; ++i) {
        m_compactShortcutRecords[i].code = static_cast<wchar_t>(L'a' + i);
        m_compactShortcutRecords[i].isSpellMode = 1;
    }

    for (int i = 0; i < 30; ++i) {
        m_macroHotkeys[i].ordinal = static_cast<unsigned short>(i);
        m_macroHotkeys[i].state = MacroHotkeyRecord::Spell;

        const wchar_t key =
            static_cast<wchar_t>((i < 26) ? (L'a' + i) : (L'A' + (i - 26)));
        m_macroHotkeys[i].text[0] = key;
        m_macroHotkeys[i].text[1] = L'\0';
    }

    m_targetOptionRows[0].userEnabled = 1;
    m_targetOptionRows[0].monsterEnabled = 1;
    m_targetOptionRows[1].userEnabled = 1;
    m_targetOptionRows[1].monsterEnabled = 0;

    for (int i = 0; i < 20; ++i)
        m_profileStringSlots[i].Assign(L"");

    m_blockListenNames.Clear();
}

// UID:00030Y | by-memory/0x0048eed0-0x0048f3f1.RegistryConfigInitializeDefaults.md | Completion:88 | Confidence:90
void RegistryConfig::InitializeDefaults()
{
    m_startupServerId = 1;
    m_fontIndex = 0;
    m_iconsPaneReducedMode = false;
    m_startupPort = 0;
    m_startupConnectionMode = 5;
    m_terminalBaudRate = 57600;

    m_soundEnabled = true;
    m_soundVolume = 100;
    m_musicEnabled = true;
    m_musicVolume = 100;

    m_mapEffectEnabled = true;
    m_sayWithEnter = true;
    m_doubleClickEnabled = true;
    m_autoMoveEnabled = false;
    m_balloonEnabled = true;
    m_shadowEnabled = true;
    m_showUserNameMode = 1;
    m_graphicsSetting = 2;
    m_tabVSwap = false;
    m_showDamage = true;
    m_groupBarEnabled = true;
    m_carnageColorEnabled = true;
    m_orbTargetShare = false;
    m_f1Swap = false;
    m_hearSnoreMode = 1;
    m_seeThroughEnabled = true;
    m_hearEmotions = true;

    m_paletteColorOverrides[0] = 10;
    m_paletteColorOverrides[1] = static_cast<unsigned short>(-1);
    m_paletteColorOverrides[2] = 17;
    m_paletteColorOverrides[3] = 11;

    m_serverEndpointPrefix = 0;

    InitializeUserDataDefaults();

    for (int i = 0; i < 21; ++i) {
        m_dialogPositions[i].state = 1;
        m_dialogPositions[i].position.Set(g_screenWidth / 2, g_screenHeight / 2);
    }

    m_dialogPositions[13].state = 2;
    m_dialogPositions[13].position.Set(11, 432);

    m_selectedServerId = -1;
    m_multiServerListEnabled = false;

    m_soundLatency = 16;
    m_soundFrequency = 1;
    m_musicSourceMode = 0;
    m_redbookDriveLetter = 0;
    m_randomizeMusicOrder = false;
    m_musicRepeatEnabled = false;
    m_musicFolderPath.Assign(L"");

    m_systemMessageHeight = 70;
}

// UID:0002P7 | by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md | Completion:88 | Confidence:90
void RegistryConfig::SaveToRegistry()
{
    HKEY rootKey = 0;
    HKEY childKey = 0;
    DWORD disposition = 0;

    wchar_t currentDirectory[MAX_PATH];

    if (RegCreateKeyExW(HKEY_CURRENT_USER,
                        L"Software\\Nexon\\Kingdom of the Winds",
                        0,
                        0,
                        0,
                        KEY_WRITE,
                        0,
                        &rootKey,
                        &disposition) != ERROR_SUCCESS)
    {
        return;
    }

    if (m_logDataText)
        WriteBinaryWideStringValue(rootKey, L"LogData", m_logDataText);

    GetCurrentDirectoryW(_countof(currentDirectory), currentDirectory);
    WriteStringValue(rootKey, L"Location", currentDirectory);
    WriteStringValue(rootKey, L"LastServer", m_lastServerName);

    WriteDwordValue(rootKey, L"Font", m_fontIndex);
    WriteDwordValue(rootKey, L"Icons", m_iconsPaneReducedMode);
    WriteDwordValue(rootKey, L"Sound", m_soundEnabled);
    WriteDwordValue(rootKey, L"SoundVolume", m_soundVolume);
    WriteDwordValue(rootKey, L"Music", m_musicEnabled);
    WriteDwordValue(rootKey, L"MusicVolume", m_musicVolume);
    WriteDwordValue(rootKey, L"DoubleClick", m_doubleClickEnabled);
    WriteDwordValue(rootKey, L"AutoMove", m_autoMoveEnabled);
    WriteDwordValue(rootKey, L"TabVSwap", m_tabVSwap);
    WriteDwordValue(rootKey, L"ShowDamage", m_showDamage);
    WriteDwordValue(rootKey, L"GroupBar", m_groupBarEnabled);
    WriteDwordValue(rootKey, L"CarnageColor", m_carnageColorEnabled);
    WriteDwordValue(rootKey, L"Shadow", m_shadowEnabled);
    WriteDwordValue(rootKey, L"Balloon", m_balloonEnabled);
    WriteDwordValue(rootKey, L"GraphicsSetting", m_graphicsSetting);
    WriteDwordValue(rootKey, L"orbTargetShare", m_orbTargetShare);
    WriteDwordValue(rootKey, L"f1Swap", m_f1Swap);
    WriteDwordValue(rootKey, L"ShowUserName", m_showUserNameMode);
    WriteDwordValue(rootKey, L"HearSnore", m_hearSnoreMode);
    WriteDwordValue(rootKey, L"SeeThrough", m_seeThroughEnabled);
    WriteDwordValue(rootKey, L"SayWithEnter", m_sayWithEnter);
    WriteDwordValue(rootKey, L"HearEmotions", m_hearEmotions);
    WriteDwordValue(rootKey, L"MapEffect", m_mapEffectEnabled);

    WriteDwordValue(rootKey, L"MusicType", m_musicSourceMode);
    WriteDwordValue(rootKey, L"MusicType", m_musicSourceMode);
    WriteStringValue(rootKey, L"MP3Dir", m_musicFolderPath);
    WriteDwordValue(rootKey, L"MusicCdRomDrive", m_redbookDriveLetter);
    WriteDwordValue(rootKey, L"PlayRandom", m_randomizeMusicOrder);
    WriteDwordValue(rootKey, L"PlayRepeat", m_musicRepeatEnabled);
    WriteDwordValue(rootKey, L"SoundFreq", m_soundFrequency);

    const DWORD chatWindow =
        PackChatWindowValue(m_chatVisibleLineCount,
                            m_chatHandleModeIndex,
                            m_secondaryChatEnabled,
                            m_chatHandleLeftToggle);
    WriteDwordValue(rootKey, L"ChatWindow", chatWindow);
    WriteBinaryValue(rootKey, L"ChatColor", m_chatColorPairs, sizeof(m_chatColorPairs));

    for (int i = 0; i < 4; ++i) {
        wchar_t valueName[32];
        swprintf_s(valueName, _countof(valueName), L"Color%d", i);
        WriteDwordValue(rootKey, valueName, m_paletteColorOverrides[i]);
    }

    WriteDwordValue(rootKey, L"ClickMove", m_clickMoveEnabled);
    WriteDwordValue(rootKey, L"ClickLook", m_clickLookEnabled);
    WriteDwordValue(rootKey, L"SystemMessageHeight", m_systemMessageHeight);

    RegDeleteKeyW(rootKey, L"Midi");
    if (RegCreateKeyExW(rootKey, L"Midi", 0, 0, 0, KEY_WRITE, 0, &childKey, &disposition) == ERROR_SUCCESS) {
        SaveMidiRegistryValues(childKey, m_midiTrackPaths);
        RegCloseKey(childKey);
        childKey = 0;
    }

    for (int i = 0; i < 21; ++i) {
        wchar_t valueName[32];
        swprintf_s(valueName, _countof(valueName), L"DialogPos%d", i + 1);
        WriteBinaryValue(rootKey, valueName, &m_dialogPositions[i], sizeof(m_dialogPositions[i]));
    }

    if (m_multiServerEnabled && m_serverDirectory.entryCount > 0) {
        RegDeleteKeyW(rootKey, L"Servers");
        if (RegCreateKeyExW(rootKey, L"Servers", 0, 0, 0, KEY_WRITE, 0, &childKey, &disposition) != ERROR_SUCCESS) {
            RegCloseKey(rootKey);
            return;
        }

        WriteDwordValue(childKey, L"MultiServerInfoVersion", m_serverDirectory.version);
        for (int i = 0; i < m_serverDirectory.entryCount; ++i) {
            const ServerSelectEntry &entry = m_serverDirectory.entries[i];
            wchar_t valueName[64];
            wchar_t addressText[128];

            swprintf_s(addressText, _countof(addressText), L"%d:%d.%d.%d.%d:%d",
                       entry.serverId,
                       entry.address[0],
                       entry.address[1],
                       entry.address[2],
                       entry.address[3],
                       entry.port);

            swprintf_s(valueName, _countof(valueName), L"MultiServerAddr%d", i);
            WriteStringValue(childKey, valueName, addressText);
            swprintf_s(valueName, _countof(valueName), L"MultiServerName%d", i);
            WriteStringValue(childKey, valueName, entry.name);
            swprintf_s(valueName, _countof(valueName), L"MultiServerDesc%d", i);
            WriteStringValue(childKey, valueName, entry.description);
            swprintf_s(valueName, _countof(valueName), L"MultiServerAgreement%d", i);
            WriteStringValue(childKey, valueName, entry.agreementText);
        }

        RegCloseKey(childKey);
        childKey = 0;
    }

    RegCloseKey(rootKey);

    rootKey = 0;
    if (RegCreateKeyExW(HKEY_LOCAL_MACHINE,
                        L"SOFTWARE\\Nexon\\Kingdom of the Winds",
                        0,
                        0,
                        0,
                        KEY_WRITE,
                        0,
                        &rootKey,
                        &disposition) == ERROR_SUCCESS)
    {
        if (RegCreateKeyExW(rootKey,
                            currentDirectory,
                            0,
                            0,
                            0,
                            KEY_WRITE,
                            0,
                            &childKey,
                            &disposition) == ERROR_SUCCESS)
        {
            RegCloseKey(childKey);
        }

        RegCloseKey(rootKey);
    }
}

// UID:0002P8 | by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md | Completion:90 | Confidence:92
bool RegistryConfig::LoadFromRegistry()
{
    HKEY classKey = 0;
    HKEY rootKey = 0;
    HKEY midiKey = 0;
    HKEY serversKey = 0;
    DWORD disposition = 0;
    DWORD valueType = 0;
    DWORD valueSize = 0;
    DWORD dwordValue = 0;

    m_registryClassIdSeed = 0xff00ff00;

    if (RegCreateKeyExW(HKEY_CLASSES_ROOT,
                        L"NXKRI.Ctrl.1",
                        0,
                        0,
                        0,
                        KEY_ALL_ACCESS,
                        0,
                        &classKey,
                        &disposition) == ERROR_SUCCESS)
    {
        valueSize = sizeof(dwordValue);
        if (RegQueryValueExW(classKey,
                             L"CLSID",
                             0,
                             &valueType,
                             reinterpret_cast<BYTE *>(&dwordValue),
                             &valueSize) != ERROR_SUCCESS ||
            valueType != REG_DWORD ||
            valueSize != sizeof(dwordValue) ||
            dwordValue == 0)
        {
            srand(static_cast<unsigned int>(time(0)));
            dwordValue = ((rand() & 0xff) << 24) |
                         ((rand() & 0xff) << 16) |
                         ((rand() & 0xff) << 8) |
                         (rand() & 0xff);

            RegSetValueExW(classKey,
                           L"CLSID",
                           0,
                           REG_DWORD,
                           reinterpret_cast<const BYTE *>(&dwordValue),
                           sizeof(dwordValue));
        }

        m_registryClassIdSeed = dwordValue;
        RegCloseKey(classKey);
    }

    char adapterText[256];
    adapterText[0] = 0;
    BuildFirstAdapterPhysicalAddressString(adapterText, sizeof(adapterText));
    Md5BytesToBuffer(adapterText, strlen(adapterText), m_adapterPhysicalAddressDigest);

    if (RegCreateKeyExW(HKEY_CURRENT_USER,
                        L"Software\\Nexon\\Kingdom of the Winds",
                        0,
                        0,
                        0,
                        KEY_READ,
                        0,
                        &rootKey,
                        &disposition) != ERROR_SUCCESS)
    {
        return false;
    }

    ReadBinaryWideStringValue(rootKey, L"LogData", &m_logDataText);
    ReadFixedWideStringValue(rootKey, L"LastServer", m_lastServerName, _countof(m_lastServerName));

    ReadClampedWordValue(rootKey, L"Font", 3, &m_fontIndex);
    ReadClampedByteValue(rootKey, L"Icons", 1, &m_iconsPaneReducedMode);
    ReadClampedByteValue(rootKey, L"Sound", 1, &m_soundEnabled);
    ReadClampedDwordValue(rootKey, L"SoundVolume", 100, &m_soundVolume);
    ReadClampedByteValue(rootKey, L"Music", 1, &m_musicEnabled);
    ReadClampedDwordValue(rootKey, L"MusicVolume", 100, &m_musicVolume);

    m_soundLatency = 0x10;
    ReadDwordValue(rootKey, L"SoundLatency", &m_soundLatency);

    ReadClampedByteValue(rootKey, L"DoubleClick", 1, &m_doubleClickEnabled);

    // Retained compatibility read in this binary: the result is not stored.
    QueryDwordValue(rootKey, L"AutoMove", &dwordValue);

    ReadClampedByteValue(rootKey, L"TabVSwap", 1, &m_tabVSwap);
    ReadClampedByteValue(rootKey, L"ShowDamage", 1, &m_showDamage);
    ReadClampedByteValue(rootKey, L"GroupBar", 1, &m_groupBarEnabled);
    ReadClampedByteValue(rootKey, L"CarnageColor", 1, &m_carnageColorEnabled);
    ReadClampedByteValue(rootKey, L"Shadow", 1, &m_shadowEnabled);
    ReadClampedByteValue(rootKey, L"Balloon", 1, &m_balloonEnabled);
    ReadClampedDwordValue(rootKey, L"GraphicsSetting", 1, &m_graphicsSetting);
    ReadClampedByteValue(rootKey, L"orbTargetShare", 1, &m_orbTargetShare);
    ReadClampedByteValue(rootKey, L"f1Swap", 1, &m_f1Swap);
    ReadClampedByteValue(rootKey, L"ShowUserName", 2, &m_showUserNameMode);
    ReadClampedByteValue(rootKey, L"HearSnore", 2, &m_hearSnoreMode);
    ReadClampedByteValue(rootKey, L"SeeThrough", 1, &m_seeThroughEnabled);
    ReadClampedByteValue(rootKey, L"SayWithEnter", 1, &m_sayWithEnter);
    ReadClampedByteValue(rootKey, L"HearEmotions", 1, &m_hearEmotions);
    ReadClampedByteValue(rootKey, L"MapEffect", 1, &m_mapEffectEnabled);

    ReadDwordValue(rootKey, L"MusicType", &m_musicSourceMode);
    ReadStringValue(rootKey, L"MP3Dir", &m_musicFolderPath);
    ReadWordFromDwordValue(rootKey, L"MusicCdRomDrive", &m_redbookDriveLetter);
    ReadClampedByteValue(rootKey, L"PlayRandom", 1, &m_randomizeMusicOrder);
    ReadClampedByteValue(rootKey, L"PlayRepeat", 1, &m_musicRepeatEnabled);
    ReadByteFromDwordValue(rootKey, L"SoundFreq", &m_soundFrequency);

    if (!ReadChatWindowValue(rootKey,
                             &m_chatVisibleLineCount,
                             &m_chatHandleModeIndex,
                             &m_secondaryChatEnabled,
                             &m_chatHandleLeftToggle))
    {
        m_chatVisibleLineCount = 8;
        m_chatHandleModeIndex = 1;
        m_secondaryChatEnabled = true;
        m_chatHandleLeftToggle = true;
    }

    if (!ReadBinaryValue(rootKey, L"ChatColor", m_chatColorPairs, sizeof(m_chatColorPairs)))
    {
        SetDefaultChatColors();
    }

    for (int i = 0; i < 4; ++i)
    {
        wchar_t valueName[32];
        swprintf(valueName, L"Color%d", i);
        ReadWordFromDwordValue(rootKey, valueName, &m_paletteColorOverrides[i]);
    }

    ReadBoolDefaultTrue(rootKey, L"ClickMove", &m_clickMoveEnabled);
    ReadBoolDefaultTrue(rootKey, L"ClickLook", &m_clickLookEnabled);

    m_systemMessageHeight = 0x46;
    ReadDwordValue(rootKey, L"SystemMessageHeight", &m_systemMessageHeight);

    if (RegCreateKeyExW(rootKey,
                        L"Midi",
                        0,
                        0,
                        0,
                        KEY_READ,
                        0,
                        &midiKey,
                        &disposition) != ERROR_SUCCESS)
    {
        RegCloseKey(rootKey);
        return false;
    }

    LoadMidiRegistryValues(midiKey, m_midiTrackPaths);
    RegCloseKey(midiKey);

    for (int i = 0; i < 21; ++i)
    {
        wchar_t valueName[32];
        swprintf(valueName, L"DialogPos%d", i);
        ReadBinaryValue(rootKey, valueName, &m_dialogPositions[i], sizeof(m_dialogPositions[i]));
    }

    if (RegCreateKeyExW(rootKey,
                        L"Servers",
                        0,
                        0,
                        0,
                        KEY_READ,
                        0,
                        &serversKey,
                        &disposition) == ERROR_SUCCESS)
    {
        m_serverDirectory.ReleaseOwnedBuffers();

        ReadNonNegativeByteValue(serversKey,
                                 L"MultiServerInfoVersion",
                                 &m_serverDirectory.version);

        if (!LoadMultiServerEntries(serversKey, &m_serverDirectory))
        {
            m_serverDirectory.ReleaseOwnedBuffers();
            RegCloseKey(serversKey);
            RegCloseKey(rootKey);
            return false;
        }

        RegCloseKey(serversKey);
    }

    RegCloseKey(rootKey);

    for (int i = 0; i < 2; ++i)
    {
        if (SystemDirectoryFileExists(kConfigHelperProbeFileNames[i]))
        {
            m_systemHelperFlags = 0x0a01;
            break;
        }
    }

    return true;
}

// UID:000480 | by-memory/0x00612610-0x00612614.RegistryConfigRttiLocatorPointer.md | Completion:92 | Confidence:95
// Compiler-generated MSVC RTTI complete-object-locator pointer for RegistryConfig.
// The RegistryConfig class declaration regenerates this primary vftable[-1] metadata.
// No standalone source object or raw RTTI dword is emitted here.

// UID:000481 | by-memory/0x00612614-0x00612628.RegistryConfigVtableData.md | Completion:92 | Confidence:95
// Compiler-generated MSVC primary vtable for RegistryConfig.
// The RegistryConfig virtual declaration and overrides regenerate these five slots.
// No standalone source array or raw vtable dword table is emitted here.

// UID:0003FW | by-memory/0x00617420-0x006178c8.RegistryConfigOptionStringData.md | Completion:88 | Confidence:91
// RegistryConfig option-key string literals are covered by SaveToRegistry() and LoadFromRegistry() source-use sites.
// No standalone pooled-string cluster declaration is emitted for 0x00617420-0x006178c8.

// UID:0001VR | by-type/by-struct/RegistryConfigUserProfileBlock.md | Completion:90 | Confidence:92
// RegistryConfigUserProfileBlock is a layout documentation slice inside RegistryConfig, not a confirmed standalone source struct.
// Emit exact nested row types such as MacroHotkeyRecord separately; keep this aggregate layout page comment-only.

// UID:0001V1 | by-type/by-struct/MacroHotkeyRecord.md | Completion:88 | Confidence:90
struct MacroHotkeyRecord
{
    enum State {
        Text = 1,
        Spell = 2,
        Item = 3
    };

    unsigned short ordinal;
    State state;
    wchar_t text[0x80];
};

// UID:000279 | by-memory/0x0066d468-0x0066d47c.CommandLineAndConfigStringPointers.md | Completion:92 | Confidence:94
static const wchar_t *g_unitelOnlyVersionMessage =
    L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 \uC720\uB2C8\uD154 \uC804\uC6A9\uC785\uB2C8\uB2E4.";

static const wchar_t *kConfigHelperProbeFileNames[] =
{
    L"mscfg.dll",
    L"grcframe.exe"
};

static const wchar_t *kCommandLineTokenDelimiters = L"/ \t";
static const wchar_t *g_startupLauncherMissingArgumentText =
    L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 HITEL2000 \uC804\uC6A9\uC785\uB2C8\uB2E4.";

// UID:00032G | by-memory/0x0048e950-0x0048ea6e.RegistryConfigTypeProbeRaw.md | Completion:88 | Confidence:89
static unsigned char QueryInstallRegistryType()
{
    HKEY rootKey;
    HKEY installKey;
    DWORD disposition;
    DWORD valueType;
    DWORD valueSize;
    DWORD typeValue;
    wchar_t currentDirectory[MAX_PATH];
    unsigned char result = 0;

    if (RegCreateKeyExW(HKEY_LOCAL_MACHINE,
                        L"SOFTWARE\\Nexon\\Kingdom of the Winds",
                        0,
                        0,
                        0,
                        KEY_READ,
                        0,
                        &rootKey,
                        &disposition) != ERROR_SUCCESS)
    {
        return 0;
    }

    GetCurrentDirectoryW(MAX_PATH, currentDirectory);

    if (RegCreateKeyExW(rootKey,
                        currentDirectory,
                        0,
                        0,
                        0,
                        KEY_READ,
                        0,
                        &installKey,
                        &disposition) != ERROR_SUCCESS)
    {
        RegCloseKey(rootKey);
        return 0;
    }

    valueSize = sizeof(typeValue);
    if (RegQueryValueExW(installKey,
                         L"Type",
                         0,
                         &valueType,
                         reinterpret_cast<BYTE *>(&typeValue),
                         &valueSize) == ERROR_SUCCESS &&
        valueType == REG_DWORD &&
        valueSize == sizeof(typeValue))
    {
        result = static_cast<unsigned char>(typeValue);
    }

    RegCloseKey(installKey);
    RegCloseKey(rootKey);
    return result;
}

// UID:0002BG | by-memory/0x0048f400-0x0048f4cf.CommandLineArgumentCounter.md | Completion:88 | Confidence:89
static void ScanStartupCommandLineTokenLimit(RegistryConfig *config)
{
    wchar_t commandLine[1024];
    wchar_t *scan;
    wchar_t *context;
    wchar_t *token;
    int tokenCount;

    GetMemoryMan_516030();
    config->m_startupReady = 1;

    wcscpy_s(commandLine, 1024, GetCommandLineW());

    scan = wcschr(commandLine, L'"');
    if (scan != NULL)
        scan = wcschr(scan + 1, L'"');
    else
        scan = wcschr(commandLine, L' ');

    if (scan == NULL)
        return;

    context = NULL;
    token = wcstok_s(scan + 1, L" ", &context);
    if (token == NULL) {
        config->m_startupReady = 1;
        return;
    }

    tokenCount = 0;
    do {
        ++tokenCount;
        if (tokenCount >= 8)
            return;

        token = wcstok_s(NULL, L" ", &context);
    } while (token != NULL);

    config->m_startupReady = 1;
}

// UID:000220 | by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md | Completion:90 | Confidence:92
// RegistryCommandLineParsers is an aggregate/index over exact parser children.
// The twelve child helpers emit individually under RegistryConfig.cpp; no monolithic parser-island function is emitted here.

// UID:0002BH | by-memory/0x0048f4d0-0x0048f6cb.StartupHostPortCommandLineParser.md | Completion:90 | Confidence:92
static void ParseUnitelRelayStartupHostPort(RegistryConfig *config)
{
    MemoryMan *memoryMan = MemoryMan::GetMemoryMan();
    wchar_t portText[12];
    char ansiHost[128];

    const wchar_t *commandLine = GetCommandLineW();

    const wchar_t *hostText = wcsstr(commandLine, L"IP");
    if (hostText == NULL)
        AbortWithLauncherMessage(g_unitelOnlyVersionMessage);

    hostText += 3;
    const wchar_t *hostEnd = wcschr(hostText, L'&');
    if (hostEnd == NULL)
        AbortWithLauncherMessage(g_unitelOnlyVersionMessage);

    const wchar_t *portStart = wcsstr(commandLine, L"PO");
    if (portStart == NULL)
        AbortWithLauncherMessage(g_unitelOnlyVersionMessage);

    portStart += 3;
    const wchar_t *portEnd = wcschr(portStart, L'&');
    if (portEnd == NULL)
        AbortLauncherStartupWithoutMessage();

    size_t hostLength = static_cast<size_t>(hostEnd - hostText);
    memmove(config->m_startupHostName,
            hostText,
            hostLength * sizeof(wchar_t));
    config->m_startupHostName[hostLength] = L'\0';

    int converted = WideCharToMultiByte(CP_ACP,
                                        0,
                                        config->m_startupHostName,
                                        static_cast<int>(hostLength),
                                        ansiHost,
                                        127,
                                        NULL,
                                        NULL);
    if (converted >= 128)
        __report_rangecheckfailure();
    ansiHost[converted] = '\0';

    hostent *host = gethostbyname(ansiHost);
    if (host == NULL)
    {
        AbortWithLauncherHostMessage(L"Unitel Relay\uC758 \uC8FC\uC18C\uB97C \uC5BB\uB294 \uB370 \uC2E4\uD328\uD588\uC2B5\uB2C8\uB2E4(host : \"%s\" err : %d).",
                                     config->m_startupHostName,
                                     WSAGetLastError());
    }

    memoryMan->MemmoveWrapper(config->m_startupAddress,
                              host->h_addr_list[0],
                              4);

    size_t portLength = static_cast<size_t>(portEnd - portStart);
    memmove(portText, portStart, portLength * sizeof(wchar_t));
    portText[portLength] = L'\0';

    config->m_startupPort = _wtol(portText);
    config->m_startupReady = 1;
    config->m_startupConnectionMode = 5;
}

// UID:0002BI | by-memory/0x0048f6d0-0x0048fc96.NetsgoStartupAuthenticationParser.md | Completion:90 | Confidence:92
static void ParseNetsgoStartupAuthentication(RegistryConfig *config)
{
    wchar_t commandLine[1024];
    wchar_t launchCommand[256];
    wchar_t tokens[12][128];
    wchar_t atomName[128];
    wchar_t hostScratch[128];
    char ansiHost[256];

    int tokenCount = TokenizeLauncherCommandLine(GetCommandLineW(),
                                                 commandLine,
                                                 1024,
                                                 tokens,
                                                 12,
                                                 launchCommand,
                                                 256,
                                                 L"Baram.exe ",
                                                 L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 Netsgo \uC804\uC6A9\uC785\uB2C8\uB2E4.( \uC785\uB825\uC815\uBCF4\uC5D0 \uC624\uB958\uAC00 \uC788\uC2B5\uB2C8\uB2E4 - 0. )",
                                                 L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 Netsgo \uC804\uC6A9\uC785\uB2C8\uB2E4.( \uC785\uB825\uC815\uBCF4\uC5D0 \uC624\uB958\uAC00 \uC788\uC2B5\uB2C8\uB2E4. - 1 )");

    if (tokenCount > 12)
        AbortWithNetsgoStartupError(L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 Netsgo \uC804\uC6A9\uC785\uB2C8\uB2E4.( \uC785\uB825\uC815\uBCF4\uC5D0 \uC624\uB958\uAC00 \uC788\uC2B5\uB2C8\uB2E4. Too many arguments )");

    // Twelve total tokens means the executable token plus eleven launcher arguments.
    if (tokenCount != 12)
        AbortWithNetsgoStartupError(L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 Netsgo \uC804\uC6A9\uC785\uB2C8\uB2E4.( \uC785\uB825\uC815\uBCF4\uC5D0 \uC624\uB958\uAC00 \uC788\uC2B5\uB2C8\uB2E4 - 2. )");

    if (wcscmp(tokens[9], L"netsgo") != 0)
        AbortWithNetsgoStartupError(L"\uC774 \uC11C\uBE44\uC2A4\uB294 Netsgo\uB97C \uC774\uC6A9\uD558\uC154\uC57C \uD569\uB2C8\uB2E4. ");

    int atomValue = _wtol(tokens[10]);
    if (atomValue <= 0)
        AbortWithNetsgoStartupError(L"\uC804\uB2EC\uB41C \uC815\uBCF4\uC5D0 \uC624\uB958\uAC00 \uC788\uC2B5\uB2C8\uB2E4. ( invalid num ) ");

    int browserVersion = _wtol(tokens[11]);
    if (browserVersion < 1000)
        AbortWithNetsgoStartupError(L"\uC774 \uC11C\uBE44\uC2A4\uB294 \uC0C1\uC704\uBC84\uC804(\uBC84\uC804 1.0 \uC774\uC0C1)\uC758 Netsgo \uC804\uC6A9 \uBE0C\uB77C\uC6B0\uC800\uB97C \uC774\uC6A9\uD558\uC154\uC57C \uD569\uB2C8\uB2E4. ");

    if (GlobalGetAtomNameW(static_cast<ATOM>(atomValue & 0xffff),
                           atomName,
                           128) == 0 ||
        wcscmp(tokens[2], atomName) != 0)
    {
        AbortWithNetsgoStartupError(L"Netsgo \uC804\uC6A9 \uBE0C\uB77C\uC6B0\uC800\uB97C \uD1B5\uD574\uC11C\uB9CC \uBCF8 \uC11C\uBE44\uC2A4\uB97C \uC774\uC6A9\uD558\uC2E4 \uC218 \uC788\uC2B5\uB2C8\uB2E4.( Validation Check Error )");
    }

    wcscpy_s(hostScratch, 128, tokens[3]);

    if (hostScratch[0] >= L'0' && hostScratch[0] <= L'9')
    {
        const wchar_t *part = hostScratch;
        for (int i = 0; i < 4; ++i)
        {
            config->m_startupAddress[i] = static_cast<unsigned char>(_wtol(part));

            if (i != 3)
            {
                const wchar_t *dot = wcschr(part, L'.');
                if (dot == 0)
                    AbortWithNetsgoStartupError(L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 Netsgo \uC804\uC6A9\uC785\uB2C8\uB2E4.( \uC785\uB825\uC815\uBCF4\uC5D0 \uC624\uB958\uAC00 \uC788\uC2B5\uB2C8\uB2E4 - 3. )");
                part = dot + 1;
            }
        }
    }
    else
    {
        wcscpy_s(config->m_startupHostName, 128, hostScratch);

        int converted = WideCharToMultiByte(CP_ACP,
                                            0,
                                            config->m_startupHostName,
                                            -1,
                                            ansiHost,
                                            256,
                                            0,
                                            0);
        if (converted <= 0 || converted >= 256)
            AbortWithNetsgoStartupError(L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 Netsgo \uC804\uC6A9\uC785\uB2C8\uB2E4.( \uC785\uB825\uC815\uBCF4\uC5D0 \uC624\uB958\uAC00 \uC788\uC2B5\uB2C8\uB2E4 - 3. )");

        hostent *host = gethostbyname(ansiHost);
        if (host == 0 || host->h_addr_list == 0 || host->h_addr_list[0] == 0)
            AbortWithNetsgoStartupError(L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 Netsgo \uC804\uC6A9\uC785\uB2C8\uB2E4.( \uC785\uB825\uC815\uBCF4\uC5D0 \uC624\uB958\uAC00 \uC788\uC2B5\uB2C8\uB2E4 - 3. )");

        memcpy(config->m_startupAddress, host->h_addr_list[0], 4);
    }

    config->m_startupPort = static_cast<unsigned short>(_wtol(tokens[4]));
    config->m_startupServerId = static_cast<unsigned short>(_wtol(tokens[5]));
    wcscpy_s(config->m_startupLaunchCommand, 256, launchCommand);

    config->m_startupReady = 1;
    config->m_startupConnectionMode = 5;
}

// UID:0002BJ | by-memory/0x0048fca0-0x004901f0.ThrunetStartupAuthFileParser.md | Completion:91 | Confidence:93
struct __declspec(uuid("A355E808-E854-4C43-9D7F-EE8A16DDA67F"))
IThrunetUrlCheck : public IDispatch
{
    virtual HRESULT STDMETHODCALLTYPE CheckUrl(BSTR request,
                                                BSTR *response) = 0;
};

static void ParseThrunetStartupAuthenticationFile(RegistryConfig *config)
{
    MemoryMan *memoryMan = MemoryMan::GetMemoryMan();
    wchar_t commandLine[1024];
    wchar_t authFilePath[128];
    wchar_t serverLine[128];
    wchar_t portLine[128];
    char authRequest[256];
    char hostName[256];

    const wchar_t *fileArgument = CopyLauncherCommandLineTail(GetCommandLineW(),
                                                              commandLine,
                                                              _countof(commandLine));
    CopyLauncherWideArgument(authFilePath, _countof(authFilePath), fileArgument);

    FILE *authFile = g_pfnWideOpenFile(authFilePath, L"ro");
    if (authFile == NULL)
        AbortWithLauncherMessage(L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 \uB450\uB8E8\uB137 \uC804\uC6A9\uC785\uB2C8\uB2E4.");

    ReadByteLineAsWide(authFile, serverLine, _countof(serverLine));

    if (serverLine[0] >= L'0' && serverLine[0] <= L'9')
    {
        const wchar_t *part = serverLine;

        for (int i = 0; i < 4; ++i)
        {
            config->m_startupAddress[i] = static_cast<unsigned char>(_wtol(part));
            if (i != 3)
                part = wcschr(part, L'.') + 1;
        }
    }
    else
    {
        const wchar_t *space = wcschr(serverLine, L' ');
        size_t hostLength = space != NULL ? static_cast<size_t>(space - serverLine)
                                          : wcslen(serverLine);

        memoryMan->MemmoveWrapper(config->m_startupHostName,
                                  serverLine,
                                  hostLength * sizeof(wchar_t));
        config->m_startupHostName[hostLength] = L'\0';

        int converted = WideCharToMultiByte(CP_ACP,
                                            0,
                                            config->m_startupHostName,
                                            static_cast<int>(hostLength),
                                            hostName,
                                            _countof(hostName),
                                            NULL,
                                            NULL);
        hostName[converted] = '\0';

        hostent *host = gethostbyname(hostName);
        if (host == NULL)
            AbortWithLauncherMessage(L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 \uB450\uB8E8\uB137 \uC804\uC6A9\uC785\uB2C8\uB2E4.( \uC785\uB825\uC815\uBCF4\uC5D0 \uC624\uB958\uAC00 \uC788\uC2B5\uB2C8\uB2E4. )");

        memoryMan->MemmoveWrapper(config->m_startupAddress, host->h_addr_list[0], 4);
    }

    ReadByteLineAsWide(authFile, portLine, _countof(portLine), 10);
    config->m_startupPort = _wtol(portLine);

    memset(authRequest, 0, sizeof(authRequest));
    fscanf(authFile, "%s", authRequest);
    fclose(authFile);

    CoInitialize(NULL);

    IThrunetUrlCheck *urlCheck = NULL;
    HRESULT hr = CreateComObjectFromProgId(reinterpret_cast<void **>(&urlCheck),
                                           "thrunet.clsURLCHK",
                                           NULL,
                                           CLSCTX_INPROC_SERVER |
                                               CLSCTX_INPROC_HANDLER |
                                               CLSCTX_LOCAL_SERVER |
                                               CLSCTX_REMOTE_SERVER);
    if (FAILED(hr))
        AbortWithLauncherMessage(L"\uC0AC\uC6A9\uC790 \uC778\uC99D \uBAA8\uB4C8\uC744 \uC5BB\uB294\uB370 \uC2E4\uD328\uD588\uC2B5\uB2C8\uB2E4.");

    _bstr_t request(authRequest);
    BSTR rawResponse = NULL;
    hr = urlCheck->CheckUrl(request, &rawResponse);
    if (FAILED(hr))
        _com_issue_errorex(hr, urlCheck, __uuidof(IThrunetUrlCheck));

    _bstr_t response(rawResponse, false);
    char *tokenText = _strdup(static_cast<const char *>(response));
    if (tokenText[0] == '*')
        AbortWithLauncherMessage(L"\uC0AC\uC6A9\uC790 \uC778\uC99D\uC5D0 \uC2E4\uD328\uD588\uC2B5\uB2C8\uB2E4.");

    strcpy_s(config->m_thrunetAuthenticationToken, 64, tokenText);
    config->m_startupReady = 1;
    config->m_startupConnectionMode = 5;

    free(tokenText);
    urlCheck->Release();
}

// UID:0002BK | by-memory/0x00490200-0x0049050a.LgInternetSessionLauncherParser.md | Completion:90 | Confidence:92
static void ParseLgInternetSessionLauncher(RegistryConfig *config)
{
    struct LgInternetSessionParameters
    {
        char sessionId[32];
        char sessionKey[32];
        char host[32];
        int port;
    };

    typedef int (WINAPI *WaitForSessionParameterProc)(
        LgInternetSessionParameters *parameters);

    wchar_t commandLine[1024];
    char hostText[128];
    char *tokenContext;
    LgInternetSessionParameters sessionParameters;

    wcscpy_s(commandLine, _countof(commandLine), GetCommandLineW());

    wchar_t *modeText = wcschr(commandLine, L'/');
    if (modeText == NULL)
        AbortWithLauncherMessage(L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 Channel i \uC804\uC6A9\uC785\uB2C8\uB2E4.");

    size_t modeLength = wcslen(modeText);
    if (modeLength == 4)
    {
        if (wcsncmp(modeText, L"/lgi", 4) != 0)
            AbortWithLauncherMessage(L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 Channel i \uC804\uC6A9\uC785\uB2C8\uB2E4.");
    }
    else
    {
        if (modeLength <= 4 || wcsncmp(modeText, L"/lgi ", 5) != 0)
            AbortWithLauncherMessage(L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 Channel i \uC804\uC6A9\uC785\uB2C8\uB2E4.");
    }

    HMODULE channelModule = g_pfnLoadLibraryW(L"chigamec.dll");
    WaitForSessionParameterProc waitForSessionParameter =
        reinterpret_cast<WaitForSessionParameterProc>(
            GetProcAddress(channelModule, "WaitForSessionParameter"));

    int sessionResult = waitForSessionParameter(&sessionParameters);
    if (sessionResult != 0)
        AbortWithLauncherMessageFormat(L"Channel i DLL Error : code %d - \uC811\uC18D\uC911\uC778 \uCC44\uB110\uC544\uC774 ID\uC778\uC9C0 \uD655\uC778\uD558\uC2ED\uC2DC\uC624.", sessionResult);

    size_t hostLength = strlen(sessionParameters.host);
    if (hostLength >= sizeof(hostText))
        ___report_rangecheckfailure();

    memcpy(hostText, sessionParameters.host, hostLength);
    hostText[hostLength] = '\0';

    MultiByteToWideChar(CP_ACP,
                        0,
                        hostText,
                        static_cast<int>(hostLength),
                        config->m_startupHostName,
                        128);

    if (isalpha(static_cast<unsigned char>(hostText[0])))
    {
        hostent *host = gethostbyname(hostText);
        if (host == NULL)
            AbortWithLauncherHostMessage("\xC0\xCC\x20\xB9\xF6\xC0\xFC\xC0\xC7\x20\xB9\xD9\xB6\xF7" "\xC0\xC7\x20\xB3\xAA\xB6\xF3\xB4\xC2\x20\x4C\x47\x20\x49" "\x6E\x74\x65\x72\x6E\x65\x74\x20\x43\x68\x61\x6E\x6E\x65" "\x6C\x69\x20\xC0\xFC\xBF\xEB\xC0\xD4\xB4\xCF\xB4\xD9\x2E" "\x28\x20\xC0\xD4\xB7\xC2\xC1\xA4\xBA\xB8\x20\x22\x25\x73" "\x22\x20\xBF\xA1\x20\xBF\xC0\xB7\xF9\xB0\xA1\x20\xC0\xD6" "\xBD\xC0\xB4\xCF\xB4\xD9\x2E", hostText);

        strcpy_s(reinterpret_cast<char *>(config->m_startupAddress),
                 16,
                 host->h_addr_list[0]);
    }
    else
    {
        tokenContext = NULL;
        char *part = strtok_s(hostText, ".", &tokenContext);
        if (part == NULL)
            return;

        config->m_startupAddress[0] =
            static_cast<unsigned char>(strtoul(part, NULL, 10));

        for (int i = 1; i < 4; ++i)
        {
            part = strtok_s(NULL, ".", &tokenContext);
            if (part == NULL)
                return;

            config->m_startupAddress[i] =
                static_cast<unsigned char>(strtoul(part, NULL, 10));
        }
    }

    config->m_startupPort = sessionParameters.port;
    config->m_startupConnectionMode = 5;
    strcpy_s(config->m_lgInternetSessionId, 64, sessionParameters.sessionId);
    strcpy_s(config->m_lgInternetSessionKey, 64, sessionParameters.sessionKey);
    config->m_startupReady = 1;
}

// UID:0002BL | by-memory/0x00490510-0x00490809.LauncherHostPortPayloadParser.md | Completion:90 | Confidence:92
static void ParseLauncherHostPortPayload(RegistryConfig *config)
{
    MemoryMan *memoryMan = MemoryMan::GetMemoryMan();
    wchar_t commandLine[0x400];
    wchar_t *tokenContext = NULL;
    wchar_t *dotContext = NULL;
    wchar_t *tokens[8] = {};
    char ansiHost[0x80];

    wchar_t *argumentText = CopyLauncherCommandLineTail(GetCommandLineW(),
                                                        commandLine,
                                                        _countof(commandLine));
    if (argumentText == NULL)
        return;

    wchar_t *selector = wcstok_s(argumentText, L" ", &tokenContext);
    if (selector == NULL)
        return;

    int tokenCount = 0;
    wchar_t *token = NULL;
    do
    {
        ++tokenCount;
        if (tokenCount >= 8)
            return;

        token = wcstok_s(NULL, L" ", &tokenContext);
        tokens[tokenCount] = token;
    } while (token != NULL);

    if (tokenCount != 5)
        return;

    wchar_t *hostToken = tokens[1];
    wchar_t *portToken = tokens[2];
    wchar_t *payloadToken1 = tokens[3];
    wchar_t *payloadToken2 = tokens[4];

    if (hostToken[0] >= L'0' && hostToken[0] <= L'9')
    {
        wchar_t *octet = wcstok_s(hostToken, L".", &dotContext);
        if (octet == NULL)
            return;

        config->m_startupAddress[0] = static_cast<unsigned char>(_wtol(octet));
        for (int i = 1; i < 4; ++i)
        {
            octet = wcstok_s(NULL, L".", &dotContext);
            if (octet == NULL)
                return;

            config->m_startupAddress[i] = static_cast<unsigned char>(_wtol(octet));
        }
    }
    else
    {
        size_t hostLength = wcslen(hostToken);
        memoryMan->MemmoveWrapper(config->m_startupHostName,
                                  hostToken,
                                  hostLength * sizeof(wchar_t));
        config->m_startupHostName[hostLength] = L'\0';

        int converted = WideCharToMultiByte(CP_ACP,
                                            0,
                                            config->m_startupHostName,
                                            static_cast<int>(hostLength),
                                            ansiHost,
                                            _countof(ansiHost),
                                            NULL,
                                            NULL);
        if (converted >= _countof(ansiHost))
            _report_rangecheckfailure();

        ansiHost[converted] = '\0';

        hostent *host = gethostbyname(ansiHost);
        if (host == NULL)
        {
            char message[0x400];
            sprintf_s(message,
                      _countof(message),
                      "\xC0\xD4\xB7\xC2\xC1\xA4\xBA\xB8\x20\x22\x25\x73\x22\x20" "\xBF\xA1\x20\xBF\xC0\xB7\xF9\xB0\xA1\x20\xC0\xD6\xBD\xC0" "\xB4\xCF\xB4\xD9\x2E",
                      ansiHost);
            MessageBoxA(ApplicationGetMainWindowHandle(),
                        message,
                        "NWind",
                        0);
            PostQuitMessage(0);
            __loaddll(0);
            return;
        }

        memoryMan->MemmoveWrapper(config->m_startupAddress,
                                  host->h_addr_list[0],
                                  4);
    }

    config->m_startupPort = _wtol(portToken);
    config->m_startupReady = 1;
    config->m_startupConnectionMode = 5;

    int payloadLength = static_cast<int>(wcslen(payloadToken1));
    int payloadBytes = WideCharToMultiByte(CP_ACP,
                                           0,
                                           payloadToken1,
                                           payloadLength,
                                           config->m_launcherPayload[0],
                                           0x3f,
                                           NULL,
                                           NULL);
    config->m_launcherPayload[0][payloadBytes] = '\0';

    payloadLength = static_cast<int>(wcslen(payloadToken2));
    payloadBytes = WideCharToMultiByte(CP_ACP,
                                       0,
                                       payloadToken2,
                                       payloadLength,
                                       config->m_launcherPayload[1],
                                       0x3f,
                                       NULL,
                                       NULL);
    config->m_launcherPayload[1][payloadBytes] = '\0';
}

// UID:0002BM | by-memory/0x00490810-0x00490b01.MihosoftLauncherParser.md | Completion:90 | Confidence:92
static void ParseMihosoftLauncher(RegistryConfig *config)
{
    MemoryMan *memoryMan = MemoryMan::GetMemoryMan();
    wchar_t commandLine[1024];
    wchar_t *tokens[8];
    wchar_t *tokenContext;
    char ansiHost[128];

    wchar_t *argumentText = CopyLauncherCommandLineTail(GetCommandLineW(),
                                                        commandLine,
                                                        _countof(commandLine));
    if (argumentText == NULL)
        return;

    int tokenCount = 0;
    tokenContext = NULL;

    wchar_t *token = wcstok_s(argumentText, L" ", &tokenContext);
    while (token != NULL)
    {
        if (tokenCount >= _countof(tokens))
            return;

        tokens[tokenCount++] = token;
        token = wcstok_s(NULL, L" ", &tokenContext);
    }

    if (tokenCount < 3 || _wcsicmp(tokens[0], L"Mihosoft") != 0)
        AbortWithLauncherMessage(L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 \uC804\uC6A9 \uD074\uB77C\uC774\uC5B8\uD2B8\uC785\uB2C8\uB2E4. \uC785\uB825\uC815\uBCF4\uC5D0 \uC624\uB958\uAC00 \uC788\uC2B5\uB2C8\uB2E4.");

    wchar_t *hostText = tokens[1];
    wchar_t *portText = tokens[2];

    if (hostText[0] >= L'0' && hostText[0] <= L'9')
    {
        tokenContext = NULL;
        wchar_t *part = wcstok_s(hostText, L".", &tokenContext);

        for (int i = 0; i < 4; ++i)
        {
            if (part == NULL)
                return;

            config->m_startupAddress[i] =
                static_cast<unsigned char>(_wtol(part));

            part = wcstok_s(NULL, L".", &tokenContext);
        }
    }
    else
    {
        size_t hostLength = wcslen(hostText);
        memoryMan->MemmoveWrapper(config->m_startupHostName,
                                  hostText,
                                  hostLength * sizeof(wchar_t));
        config->m_startupHostName[hostLength] = L'\0';

        int converted = WideCharToMultiByte(CP_ACP,
                                            0,
                                            config->m_startupHostName,
                                            static_cast<int>(hostLength),
                                            ansiHost,
                                            _countof(ansiHost),
                                            NULL,
                                            NULL);
        if (converted >= _countof(ansiHost))
            ReportRangeCheckFailure();

        ansiHost[converted] = '\0';

        hostent *host = gethostbyname(ansiHost);
        if (host == NULL)
            AbortWithLauncherHostMessage(L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 \uC804\uC6A9 \uD074\uB77C\uC774\uC5B8\uD2B8\uC785\uB2C8\uB2E4. \uC785\uB825\uC815\uBCF4 \"%s\" \uC5D0 \uC624\uB958\uAC00 \uC788\uC2B5\uB2C8\uB2E4.", hostText);

        memoryMan->MemmoveWrapper(config->m_startupAddress,
                                  host->h_addr_list[0],
                                  4);
    }

    config->m_startupPort = _wtol(portText);
    config->m_startupReady = 1;
    config->m_startupConnectionMode = 5;
}

// UID:0002BN | by-memory/0x00490b10-0x004910c0.ComBackedLauncherAuthenticationParser.md | Completion:92 | Confidence:94
struct __declspec(uuid("87BF5B0C-F5AB-4F48-AC8C-1FE3590E18E0"))
ILauncherAuthentication : public IDispatch
{
    virtual HRESULT STDMETHODCALLTYPE ReservedLauncherMethod7() = 0;
    virtual HRESULT STDMETHODCALLTYPE SetLaunchCommand(BSTR command) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetEndpoint(BSTR *endpoint) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetAuthenticationToken(
        unsigned int *token) = 0;
};

_COM_SMARTPTR_TYPEDEF(ILauncherAuthentication,
                      __uuidof(ILauncherAuthentication));

class __declspec(uuid("532518F9-3131-4C87-AEB0-021F8AA6FDD8"))
ExciteGameLauncherAuthentication;

static _bstr_t GetExciteGameLauncherEndpoint(
    ILauncherAuthentication *launcher)
{
    BSTR endpoint = 0;
    HRESULT hr = launcher->GetEndpoint(&endpoint);
    if (FAILED(hr))
        _com_issue_errorex(hr, launcher, __uuidof(ILauncherAuthentication));
    return _bstr_t(endpoint, false);
}

static void ParseExciteGameLauncherAuthentication(RegistryConfig *config)
{
    wchar_t commandLine[1024];
    wchar_t endpointScratch[256];
    wchar_t *tokenContext;
    char ansiHost[128];

    const wchar_t *argumentText = CopyLauncherCommandLineTail(GetCommandLineW(),
                                                              commandLine,
                                                              1024);
    if (argumentText == 0)
        return;

    CoInitialize(0);

    IUnknown *createdObject = 0;
    config->m_launcherAuthenticationObject =
        new ILauncherAuthenticationPtr;

    HRESULT hr = CoCreateInstance(__uuidof(ExciteGameLauncherAuthentication),
                                  0,
                                  CLSCTX_INPROC_SERVER |
                                      CLSCTX_INPROC_HANDLER |
                                      CLSCTX_LOCAL_SERVER |
                                      CLSCTX_REMOTE_SERVER,
                                  IID_IUnknown,
                                  reinterpret_cast<void **>(&createdObject));
    if (SUCCEEDED(hr))
    {
        hr = OleRun(createdObject);
        if (SUCCEEDED(hr))
        {
            hr = createdObject->QueryInterface(
                __uuidof(ILauncherAuthentication),
                reinterpret_cast<void **>(
                    &*config->m_launcherAuthenticationObject));
        }
        createdObject->Release();
    }

    if (FAILED(hr) || !*config->m_launcherAuthenticationObject)
        AbortWithLauncherMessage(L"\uAD6C\uC131\uC694\uC18C\uAC00 \uC124\uCE58\uB418\uC9C0 \uC54A\uC558\uC2B5\uB2C8\uB2E4.");

    ILauncherAuthentication *launcher =
        config->m_launcherAuthenticationObject->GetInterfacePtr();

    BSTR commandText = SysAllocString(argumentText);
    hr = launcher->SetLaunchCommand(commandText);
    SysFreeString(commandText);
    if (FAILED(hr))
        _com_issue_errorex(hr, launcher, __uuidof(ILauncherAuthentication));

    bool numericEndpoint = false;
    {
        _bstr_t firstEndpoint = GetExciteGameLauncherEndpoint(launcher);
        if (static_cast<const wchar_t *>(firstEndpoint)[0] >= L'0')
        {
            _bstr_t secondEndpoint = GetExciteGameLauncherEndpoint(launcher);
            numericEndpoint =
                static_cast<const wchar_t *>(secondEndpoint)[0] <= L'9';
        }
    }

    if (numericEndpoint)
    {
        _bstr_t endpointValue = GetExciteGameLauncherEndpoint(launcher);
        wcscpy_s(endpointScratch,
                 _countof(endpointScratch),
                 static_cast<const wchar_t *>(endpointValue));

        tokenContext = 0;
        wchar_t *part = wcstok_s(endpointScratch, L".", &tokenContext);
        if (part != 0)
        {
            config->m_startupAddress[0] =
                static_cast<unsigned char>(_wtol(part));

            for (int i = 1; i < 4; ++i)
            {
                part = wcstok_s(0, L".", &tokenContext);
                if (part == 0)
                    break;
                config->m_startupAddress[i] =
                    static_cast<unsigned char>(_wtol(part));
            }
        }
    }
    else
    {
        _bstr_t endpointLengthValue =
            GetExciteGameLauncherEndpoint(launcher);
        const wchar_t *endpointLengthText =
            static_cast<const wchar_t *>(endpointLengthValue);
        size_t endpointLength = wcslen(endpointLengthText);

        _bstr_t endpointCopyValue =
            GetExciteGameLauncherEndpoint(launcher);
        const wchar_t *endpointCopyText =
            static_cast<const wchar_t *>(endpointCopyValue);
        memcpy(config->m_startupHostName,
               endpointCopyText,
               endpointLength * sizeof(wchar_t));
        config->m_startupHostName[endpointLength] = L'\0';

        int converted = WideCharToMultiByte(CP_ACP,
                                            0,
                                            config->m_startupHostName,
                                            static_cast<int>(endpointLength),
                                            ansiHost,
                                            _countof(ansiHost),
                                            0,
                                            0);
        if (converted >= _countof(ansiHost))
            __report_rangecheckfailure();
        ansiHost[converted] = '\0';

        hostent *host = gethostbyname(ansiHost);
        if (host == 0)
        {
            _bstr_t endpointErrorValue =
                GetExciteGameLauncherEndpoint(launcher);
            AbortWithLauncherHostMessage(
                L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 Excite Game \uC804\uC6A9\uC785\uB2C8\uB2E4. \uC785\uB825\uC815\uBCF4 \"%s\" \uC5D0 \uC624\uB958\uAC00 \uC788\uC2B5\uB2C8\uB2E4.",
                static_cast<const wchar_t *>(endpointErrorValue));
        }

        memcpy(config->m_startupAddress, host->h_addr_list[0], 4);
    }

    unsigned int authenticationToken = 0;
    hr = launcher->GetAuthenticationToken(&authenticationToken);
    if (FAILED(hr))
        _com_issue_errorex(hr, launcher, __uuidof(ILauncherAuthentication));

    config->m_launcherAuthenticationToken = authenticationToken;
    config->m_startupReady = 1;
    config->m_startupConnectionMode = 5;
}

// UID:0002BO | by-memory/0x004910d0-0x00491445.BixelLauncherParser.md | Completion:90 | Confidence:92
static void ParseBixelLauncher(RegistryConfig *config)
{
    MemoryMan *memoryMan = GetMemoryMan();
    wchar_t commandLine[0x400];
    wchar_t *tokenContext = NULL;
    wchar_t *dotContext = NULL;
    wchar_t *tokens[8] = {};
    char ansiHost[0x80];

    wchar_t *argumentText = CopyLauncherCommandLineTail(GetCommandLineW(),
                                                        commandLine,
                                                        _countof(commandLine));
    if (argumentText == NULL)
        return;

    wchar_t *token = wcstok_s(argumentText, L" ", &tokenContext);
    tokens[0] = token;
    if (token == NULL)
    {
        wchar_t message[0x100];
        swprintf_s(message, _countof(message), L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 Bixel \uC804\uC6A9\uC785\uB2C8\uB2E4. \uC785\uB825\uC815\uBCF4\uC5D0 \uC624\uB958\uAC00 \uC788\uC2B5\uB2C8\uB2E4.");
        MessageBoxW(ApplicationGetMainWindowHandle(),
                    message,
                    ApplicationGetMessageCaptionW(),
                    0);
        PostQuitMessage(0);
        __loaddll(0);
        return;
    }

    int tokenCount = 0;
    do
    {
        ++tokenCount;
        if (tokenCount >= 8)
            return;

        token = wcstok_s(NULL, L" ", &tokenContext);
        tokens[tokenCount] = token;
    } while (token != NULL);

    if (tokenCount != 5 || _wcsicmp(tokens[0], L"/Bixel") != 0)
    {
        wchar_t message[0x100];
        swprintf_s(message, _countof(message), L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 Bixel \uC804\uC6A9\uC785\uB2C8\uB2E4. \uC785\uB825\uC815\uBCF4\uC5D0 \uC624\uB958\uAC00 \uC788\uC2B5\uB2C8\uB2E4.");
        MessageBoxW(ApplicationGetMainWindowHandle(),
                    message,
                    ApplicationGetMessageCaptionW(),
                    0);
        PostQuitMessage(0);
        __loaddll(0);
        return;
    }

    wchar_t *hostToken = tokens[1];
    wchar_t *portToken = tokens[2];
    wchar_t *payloadToken1 = tokens[3];
    wchar_t *payloadToken2 = tokens[4];

    if (hostToken[0] >= L'0' && hostToken[0] <= L'9')
    {
        wchar_t *octet = wcstok_s(hostToken, L".", &dotContext);
        if (octet == NULL)
            return;

        config->m_startupAddress[0] = static_cast<unsigned char>(_wtol(octet));
        for (int i = 1; i < 4; ++i)
        {
            octet = wcstok_s(NULL, L".", &dotContext);
            if (octet == NULL)
                return;

            config->m_startupAddress[i] = static_cast<unsigned char>(_wtol(octet));
        }
    }
    else
    {
        size_t hostLength = wcslen(hostToken);
        memoryMan->MemmoveWrapper(config->m_startupHostName,
                                  hostToken,
                                  hostLength * sizeof(wchar_t));
        config->m_startupHostName[hostLength] = L'\0';

        int converted = WideCharToMultiByte(CP_ACP,
                                            0,
                                            config->m_startupHostName,
                                            static_cast<int>(hostLength),
                                            ansiHost,
                                            _countof(ansiHost),
                                            NULL,
                                            NULL);
        if (converted >= _countof(ansiHost))
            _report_rangecheckfailure();

        ansiHost[converted] = '\0';

        hostent *host = gethostbyname(ansiHost);
        if (host == NULL)
        {
            wchar_t message[0x100];
            swprintf_s(message,
                       _countof(message),
                       L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 Bixel \uC804\uC6A9\uC785\uB2C8\uB2E4. \uC785\uB825\uC815\uBCF4 \"%s\" \uC5D0 \uC624\uB958\uAC00 \uC788\uC2B5\uB2C8\uB2E4.",
                       hostToken);
            MessageBoxW(ApplicationGetMainWindowHandle(),
                        message,
                        ApplicationGetMessageCaptionW(),
                        0);
            PostQuitMessage(0);
            __loaddll(0);
            return;
        }

        memoryMan->MemmoveWrapper(config->m_startupAddress,
                                  host->h_addr_list[0],
                                  4);
    }

    config->m_startupPort = _wtol(portToken);
    config->m_startupReady = 1;
    config->m_startupConnectionMode = 5;

    int payloadLength = static_cast<int>(wcslen(payloadToken1));
    int payloadBytes = WideCharToMultiByte(CP_ACP,
                                           0,
                                           payloadToken1,
                                           payloadLength,
                                           config->m_launcherPayload[0],
                                           0x3f,
                                           NULL,
                                           NULL);
    config->m_launcherPayload[0][payloadBytes] = '\0';

    payloadLength = static_cast<int>(wcslen(payloadToken2));
    payloadBytes = WideCharToMultiByte(CP_ACP,
                                       0,
                                       payloadToken2,
                                       payloadLength,
                                       config->m_launcherPayload[1],
                                       0x3f,
                                       NULL,
                                       NULL);
    config->m_launcherPayload[1][payloadBytes] = '\0';
}

// UID:0002BP | by-memory/0x00491450-0x0049178d.KwgLauncherParser.md | Completion:90 | Confidence:92
static void ParseKornetWorldLauncher(RegistryConfig *config)
{
    MemoryMan *memoryMan = MemoryMan::GetMemoryMan();
    wchar_t commandLine[0x400];
    wchar_t *tokens[8] = {};
    wchar_t *tokenContext = NULL;
    char ansiHost[0x80];

    wchar_t *argumentText = CopyLauncherCommandLineTail(GetCommandLineW(),
                                                        commandLine,
                                                        _countof(commandLine));
    if (argumentText == NULL)
        return;

    wchar_t *token = wcstok_s(argumentText, L" ", &tokenContext);
    tokens[0] = token;
    if (token == NULL)
        AbortWithLauncherMessage(L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 KornetWorld \uC804\uC6A9\uC785\uB2C8\uB2E4. \uC785\uB825\uC815\uBCF4\uC5D0 \uC624\uB958\uAC00 \uC788\uC2B5\uB2C8\uB2E4.");

    int tokenCount = 0;
    do
    {
        ++tokenCount;
        if (tokenCount >= _countof(tokens))
            return;

        token = wcstok_s(NULL, L" ", &tokenContext);
        tokens[tokenCount] = token;
    } while (token != NULL);

    if (tokenCount != 5 || _wcsicmp(tokens[0], L"/KWG") != 0)
        AbortWithLauncherMessage(L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 KornetWorld \uC804\uC6A9\uC785\uB2C8\uB2E4. \uC785\uB825\uC815\uBCF4\uC5D0 \uC624\uB958\uAC00 \uC788\uC2B5\uB2C8\uB2E4.");

    wcscpy_s(config->m_startupHostName,
             _countof(config->m_startupHostName),
             L"game.kornetworld.com");

    size_t hostLength = wcslen(config->m_startupHostName);
    int converted = WideCharToMultiByte(CP_ACP,
                                        0,
                                        config->m_startupHostName,
                                        static_cast<int>(hostLength),
                                        ansiHost,
                                        _countof(ansiHost),
                                        NULL,
                                        NULL);
    if (converted >= _countof(ansiHost))
        ReportRangeCheckFailure();

    ansiHost[converted] = '\0';

    hostent *host = gethostbyname(ansiHost);
    if (host == NULL)
        AbortWithLauncherHostMessage(L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 KornetWorld \uC804\uC6A9\uC785\uB2C8\uB2E4. \uC785\uB825\uC815\uBCF4 \"%s\" \uC5D0 \uC624\uB958\uAC00 \uC788\uC2B5\uB2C8\uB2E4.",
                                     config->m_startupHostName);

    memoryMan->MemmoveWrapper(config->m_startupAddress,
                              host->h_addr_list[0],
                              4);

    wchar_t *payloadToken1 = tokens[1];
    wchar_t *payloadToken2 = tokens[2];
    wchar_t *payloadToken3 = tokens[3];
    wchar_t *payloadToken4 = tokens[4];

    int payloadLength = static_cast<int>(wcslen(payloadToken1));
    int payloadBytes = WideCharToMultiByte(CP_ACP,
                                           0,
                                           payloadToken1,
                                           payloadLength,
                                           config->m_kornetWorldPayload[0],
                                           0x10,
                                           NULL,
                                           NULL);
    config->m_kornetWorldPayload[0][payloadBytes] = '\0';

    payloadLength = static_cast<int>(wcslen(payloadToken2));
    payloadBytes = WideCharToMultiByte(CP_ACP,
                                       0,
                                       payloadToken2,
                                       payloadLength,
                                       config->m_kornetWorldPayload[1],
                                       0x10,
                                       NULL,
                                       NULL);
    config->m_kornetWorldPayload[1][payloadBytes] = '\0';

    payloadLength = static_cast<int>(wcslen(payloadToken3));
    payloadBytes = WideCharToMultiByte(CP_ACP,
                                       0,
                                       payloadToken3,
                                       payloadLength,
                                       config->m_kornetWorldPayload[2],
                                       0x10,
                                       NULL,
                                       NULL);
    config->m_kornetWorldPayload[2][payloadBytes] = '\0';

    payloadLength = static_cast<int>(wcslen(payloadToken4));
    payloadBytes = WideCharToMultiByte(CP_ACP,
                                       0,
                                       payloadToken4,
                                       payloadLength,
                                       config->m_kornetWorldPayloadData,
                                       0x100,
                                       NULL,
                                       NULL);
    config->m_kornetWorldPayloadData[payloadBytes] = '\0';

    config->m_startupPort = 9000;
    config->m_startupReady = 1;
    config->m_startupConnectionMode = 5;
}

// UID:0002BQ | by-memory/0x00491790-0x004918dc.GameBillLauncherGate.md | Completion:90 | Confidence:92
static void ParseGameBillLauncher(RegistryConfig *config)
{
    wchar_t commandLine[1024];
    wchar_t *tokens[8];
    wchar_t *tokenContext = NULL;

    wchar_t *argumentText = CopyLauncherCommandLineTail(GetCommandLineW(),
                                                        commandLine,
                                                        _countof(commandLine));
    if (argumentText == NULL)
        return;

    tokens[0] = wcstok_s(argumentText, L" ", &tokenContext);
    if (tokens[0] == NULL)
        AbortWithLauncherMessage(L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 GameBill \uC804\uC6A9\uC785\uB2C8\uB2E4. \uC785\uB825\uC815\uBCF4\uC5D0 \uC624\uB958\uAC00 \uC788\uC2B5\uB2C8\uB2E4.");

    int tokenCount = 0;
    do
    {
        ++tokenCount;
        if (tokenCount >= _countof(tokens))
            return;

        tokens[tokenCount] = wcstok_s(NULL, L" ", &tokenContext);
    } while (tokens[tokenCount] != NULL);

    if (tokenCount <= 0 || _wcsicmp(tokens[0], L"/GameBill") != 0)
        AbortWithLauncherMessage(L"\uC774 \uBC84\uC804\uC758 \uBC14\uB78C\uC758 \uB098\uB77C\uB294 GameBill \uC804\uC6A9\uC785\uB2C8\uB2E4. \uC785\uB825\uC815\uBCF4\uC5D0 \uC624\uB958\uAC00 \uC788\uC2B5\uB2C8\uB2E4.");

    config->m_startupReady = 1;
    config->m_startupConnectionMode = 5;
}

// UID:0002BR | by-memory/0x004918e0-0x00491b28.StructuredHostPortIdLauncherParser.md | Completion:90 | Confidence:92
static void ParseStructuredHostPortIdLauncher(RegistryConfig *config)
{
    SimpleUString commandLine(GetCommandLineW());
    commandLine.MakeExclusive();

    const int hostMarker = commandLine.Find(L"/host:", 0, 6);
    if (hostMarker == -1)
        FatalError(g_startupLauncherMissingArgumentText);

    SimpleUString host;
    const int hostEnd = commandLine.FindFirstOf(kCommandLineTokenDelimiters,
                                                hostMarker + 1);
    commandLine.SubString(host, hostMarker + 6,
                          hostEnd - (hostMarker + 6));

    const int portMarker = commandLine.Find(L"/portno:", 0, 8);
    if (portMarker == -1)
        FatalError(g_startupLauncherMissingArgumentText);

    SimpleUString portText;
    const int portEnd = commandLine.FindFirstOf(kCommandLineTokenDelimiters,
                                                portMarker + 1);
    commandLine.SubString(portText, portMarker + 8,
                          portEnd - (portMarker + 8));

    const int idMarker = commandLine.Find(L"/id:", 0, 4);
    if (idMarker == -1)
        FatalError(g_startupLauncherMissingArgumentText);

    SimpleUString launcherId;
    const int idEnd = commandLine.FindFirstOf(kCommandLineTokenDelimiters,
                                              idMarker + 1);
    commandLine.SubString(launcherId, idMarker + 4,
                          idEnd - (idMarker + 4));
    launcherId.TrimLeft(kWideWhitespace);
    launcherId.TrimRight(kWideWhitespace);

    if (!ResolveHostAddressFromWideName(host.c_str(),
                                        config->m_startupAddress))
        FatalError(g_structuredLauncherHostLookupFailureText);

    config->m_startupPort = portText.ToLong();
    config->m_startupReady = 1;
    config->m_startupConnectionMode = 5;
    config->m_startupLauncherId = launcherId;
}

// UID:0002VB | by-memory/0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw.md | Completion:88 | Confidence:90
// Retained no-xref adapter physical-address formatter clone.
// The live source path is the inline adapter formatting in RegistryConfig::LoadFromRegistry(); current MCP confirms this raw unmodeled clone has no function object, no xrefs/callers, and no stored VA/RVA pointer route, so it emits no standalone body.

// UID:0003FV | by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md | Completion:92 | Confidence:94
// Compiler/linker-pooled literals and __uuidof constants are emitted at the exact consumer use sites.
// This physical read-only range has no standalone source declaration or canonical declaration owner.

// UID:0003FX | by-memory/0x006178c8-0x006179ec.RegistryConfigAdapterHelperStringData.md | Completion:88 | Confidence:91
// RegistryConfig adapter/helper literals are emitted through LoadFromRegistry(), parser helpers, and the documented raw-clone support context.
// No standalone pooled-string cluster declaration is emitted for 0x006178c8-0x006179ec.
