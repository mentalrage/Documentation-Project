// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IE
// Source by-file doc: by-file/Config.md
// UID:000031 | by-class/Config.md | Completion:94 | Confidence:95
#ifndef NEXUSTK_CONFIG_CONFIG_H
#define NEXUSTK_CONFIG_CONFIG_H

#include "../util/LObject.h"
#include "../util/Singleton.h"
#include "../util/StringBase.h"
#include "../util/StringUtil.h"

class List;

struct __declspec(uuid("87BF5B0C-F5AB-4F48-AC8C-1FE3590E18E0"))
ILauncherAuthentication;

_COM_SMARTPTR_TYPEDEF(ILauncherAuthentication,
                      __uuidof(ILauncherAuthentication));

struct ServerSelectEntry
{
    ServerSelectEntry();
    ~ServerSelectEntry();

    unsigned char serverId;
    wchar_t *name;
    wchar_t *description;
    wchar_t *agreementText;
    unsigned char address[4];
    unsigned short port;
};

struct ServerSelectDirectory
{
    ~ServerSelectDirectory();

    ServerSelectEntry entries[32];
    int entryCount;
    unsigned char version;

    void ReleaseOwnedBuffers();
};

errno_t GetLocalPlayerName(wchar_t *destination, size_t destinationCount);

struct ConfigMidiTrackPathEntry
{
    unsigned char selector;
    wchar_t path[32];
};

struct ConfigCharacterServerText
{
    unsigned short length;
    wchar_t text[256];
};

struct ConfigMacroName
{
    unsigned short length;
    wchar_t text[128];
};

struct ConfigCharacterServerMacroRow
{
    ConfigCharacterServerText playerName;
    ConfigCharacterServerText serverName;
    unsigned char macroEnabled[20];
    ConfigMacroName macroNames[20];
    wchar_t primaryMacroKeys[20];
    wchar_t primaryMacroText[20][256];
    wchar_t alternateMacroKeys[20];
    wchar_t alternateMacroText[20][256];
    int selectedMacroIndex;
};

struct ChatColorPair
{
    unsigned char foreground;
    unsigned char background;
};

struct CompactShortcutRecord
{
    wchar_t code;
    unsigned char isSpellMode;
};

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

struct TargetOptionRow
{
    unsigned char userEnabled;
    unsigned char monsterEnabled;
};

struct DialogPositionRecord
{
    int x;
    int y;
    int state;
};

class Config : public LObject, public Singleton<Config>
{
public:
    Config();
    virtual ~Config();
    virtual void SaveToRegistry() = 0;
    virtual bool LoadFromRegistry() = 0;

    int FindOrAppendFixedConfigTableRow();
    void ResetFixedConfigTableRows();

    void CopyMidiTrackPathsTo(List *destination) const;
    void CopyMidiTrackPathsFrom(List *source);
    void GetMidiTrackPath(unsigned char selector, wchar_t *destination, size_t destinationCount) const;
    void SetMidiTrackPath(unsigned char selector, const wchar_t *source);
    void SetLogData(const wchar_t *source);

    ConfigCharacterServerMacroRow m_fixedConfigRows[100];
    int m_fixedConfigRowCount;
    int m_selectedServerId;
    unsigned char m_multiServerEnabled;
    unsigned char m_alternateServerEndpointActive;
    union {
        char m_thrunetAuthenticationToken[64];
        struct {
            char m_lgInternetSessionId[64];
            char m_lgInternetSessionKey[64];
        };
        char m_launcherPayload[2][64];
        ILauncherAuthenticationPtr *m_launcherAuthenticationObject;
        struct {
            char m_kornetWorldPayload[3][16];
            char m_kornetWorldPayloadData[256];
        };
    };
    ServerSelectDirectory m_serverDirectory;
    mystr::StringBase<char> m_loginServerAddress;
    unsigned int m_loginServerPort;
    unsigned int m_auxiliaryServerPort;
    unsigned int m_serverMode;
    unsigned char m_startupConnectionMode;
    unsigned int m_terminalBaudRate;
    unsigned short m_fontIndex;
    unsigned char m_iconPaneReducedMode;
    unsigned int m_registryClassIdSeed;
    unsigned char m_adapterPhysicalAddressDigest[16];
    unsigned char m_soundEffectsEnabled;
    unsigned int m_soundVolume;
    unsigned char m_musicEnabled;
    unsigned int m_musicVolume;
    unsigned char m_mapEffectEnabled;
    unsigned char m_sayWithEnter;
    unsigned char m_doubleClickEnabled;
    unsigned char m_autoMoveEnabled;
    unsigned char m_balloonFillEnabled;
    unsigned char m_staticObjectTransparencyEnabled;
    unsigned char m_shadowEnabled;
    unsigned char m_showUserName;
    unsigned char m_selfLookTopButtonSelected;
    unsigned char m_selfLookBottomButtonSelected;
    unsigned char m_targetSelectionSuppressed;
    unsigned char m_tabVSwap;
    unsigned char m_showDamage;
    unsigned char m_groupBarEnabled;
    unsigned char m_carnageColorEnabled;
    unsigned int m_graphicsSetting;
    unsigned char m_orbTargetShare;
    unsigned char m_f1Swap;
    unsigned char m_whisperEnabled;
    unsigned char m_shoutEnabled;
    unsigned char m_adviceEnabled;
    unsigned char m_hearSnoreMode;
    unsigned char m_magicEffectsEnabled;
    unsigned char m_weatherEffectsEnabled;
    unsigned char m_fixedMovementEnabled;
    unsigned char m_mapMovementStatusOption;
    unsigned char m_seeThroughEnabled;
    unsigned char m_hearEmotions;
    unsigned int m_chatVisibleLineCount;
    unsigned int m_chatHandleModeIndex;
    unsigned char m_secondaryChatEnabled;
    unsigned char m_chatHandleLeftToggle;
    ChatColorPair m_chatColorPairs[6];
    unsigned char m_clickMoveEnabled;
    unsigned char m_clickLookEnabled;
    unsigned int m_systemMessageHeight;
    unsigned short m_powerDialogThresholdDefaults[4];
    wchar_t m_profileTextSlots[10][0x80];
    wchar_t m_legacyShortcutText[10][0x80];
    CompactShortcutRecord m_compactShortcutRecords[20];
    MacroHotkeyRecord m_macroHotkeys[30];
    TargetOptionRow m_targetOptionRows[2];
    mystr::StringBase<wchar_t> m_friendNames[20];
    wchar_t m_serverEndpointText[64];
    unsigned int m_serverEndpointPrefix;
    List *m_midiTrackPaths;
    wchar_t m_selectedProfileName[0x100];
    DialogPositionRecord m_dialogPositions[21];
    unsigned char m_startupAddress[16];
    wchar_t m_startupHostName[128];
    union {
        unsigned int m_startupPort;
        unsigned int m_launcherAuthenticationToken;
    };
    unsigned short m_startupServerId;
    unsigned short m_startupReady;
    wchar_t *m_logDataText;
    wchar_t m_lastServerName[16];
    wchar_t m_startupLaunchCommand[256];
    mystr::StringBase<wchar_t> m_startupLauncherId;
    unsigned int m_soundLatency;
    unsigned char m_clientVersionJitterEnabled;
    unsigned short m_systemHelperFlags;
    SimpleUStringVector m_blockListenNames;
    unsigned int m_musicSourceMode;
    mystr::StringBase<wchar_t> m_musicFolderPath;
    wchar_t m_redbookDriveLetter;
    unsigned char m_randomizeMusicOrder;
    unsigned char m_repeatMusic;
    unsigned char m_soundFrequency;
    unsigned char m_showMiniMapPortals;
    unsigned char m_showMiniMapNpcs;
    unsigned char m_showMiniMapPartyMembers;
};

extern Config *g_pConfig;

#endif
