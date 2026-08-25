*** UID:000031 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "Config.h"
#include "../util/List.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Config

## UID0000MS Direct Profile-Storage Contract - 2026-08-25

Profile load/import/save uses the inherited base object directly through `Config &config = *g_pConfig`. The complete formal declaration already owns `m_profileTextSlots[10][0x80]`, `m_legacyShortcutText[10][0x80]`, `m_compactShortcutRecords[20]`, `m_macroHotkeys[30]`, `m_targetOptionRows[2]`, `m_friendNames[20]`, `m_selectedProfileName[0x100]`, and the 12-byte `m_blockListenNames` vector. These are Config fields, not a nested profile aggregate and not RegistryConfig-only storage.

Only the nonvirtual default initializer needs derived dispatch: `static_cast<RegistryConfig *>(g_pConfig)->InitializeUserDataDefaults()`. After that call, ordinary field reads/writes remain base-typed. Historical profile drafts that cast the whole object to `RegistryConfig`, use raw offsets, or call the exact friend array `m_profileStringSlots` are superseded. This clarification preserves the existing `0x291918` size, every established offset, inheritance, owner/emitter route, and formal declaration.

## UID0000IF SimpleUStringVector Complete-Type Closure - 2026-08-24

- `Config.h` now includes `../util/StringUtil.h` immediately after `../util/StringBase.h`. UID0000DA supplies the complete `SimpleUStringVector` declaration through the ordered, guarded StringUtil header before Config reaches by-value member `m_blockListenNames` at `+0x2918fc`.
- The former `class SimpleUStringVector;` line is removed because a forward declaration cannot make a by-value data member complete. `List` remains forward-declared because Config stores only `List *`; the complete List definition remains a CPP-only constructor dependency.
- This is a dependency-visibility repair only. Exact `sizeof(Config)==0x291918`, member/type/order/API, Config/RegistryConfig ownership, formal CPP, direct bases, scores `94/95`, and all unrelated layout and behavior evidence remain unchanged.
- Duplicate local vector declarations, copied typedef/class bodies, transitive-include reliance, opaque replacement storage, raw offsets, and accessor/proxy workarounds remain rejected. Generated proof requires one direct StringUtil include before the Config declaration, zero vector forward declarations, and the exact by-value member after the complete included type.

## UID000480 RTTI Hierarchy And Header Closure - 2026-08-15

- Exact Config RTTI at COL `0x006457e4`, TypeDescriptor `0x00674680`, and CHD `0x00642170` proves direct nonvirtual bases `LObject` at `+0` and `Singleton<Config>` at `+4`.
- `Config.h` therefore includes complete `../util/LObject.h` and `../util/Singleton.h` definitions and declares `class Config : public LObject, public Singleton<Config>`. The former `class LObject;` forward declaration was insufficient for inheritance and is removed.
- Exact locator child [UID:000535][0x006168cc-0x006168d0.ConfigRttiLocatorPointer](by-memory/0x006168cc-0x006168d0.ConfigRttiLocatorPointer.md) precedes corrected five-slot [UID:0003FU][0x006168d0-0x006168e4.ConfigVtableData](by-memory/0x006168d0-0x006168e4.ConfigVtableData.md); `[0x006168e4,0x006168e8)` is transition padding, not a sixth slot.
- Constructor/destructor vptr stores at `0x0048e5ac`, `0x0048e7ac`, and `0x00494053` agree with the class route. The declaration, virtual methods, and two direct bases regenerate the RTTI/vtable; no raw ABI definitions belong in source.

All pre-existing Config types, fields, methods, exact `0x291918` layout, and source-facing names below remain intact. This pass changes only complete-base inclusion/inheritance and the associated RTTI/range documentation.

## UID000480 Generated Config Source Closure - 2026-08-15

- `Config.cpp` includes the complete `List` definition needed by the constructor's `new List(0x42, 0x10)` expression. The public header continues to forward-declare `List` because it stores only `List *`.
- Exact child [UID:00030S][0x0048e550-0x0048e77a.ConfigConstructor](by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md) now carries the human source constructor body. Compiler-only base/member construction, vptr installation, vector-constructor lowering, and EH scaffolding remain omitted.
- Exact child [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md) now carries ordinary `Config::~Config()` source. The hidden scalar-delete flag, object-free branch, vptr store, and automatic member/base destruction remain compiler products.
- Historical [UID:000032][ConfigEntryBlock](by-class/ConfigEntryBlock.md) emits only `ServerSelectDirectory::~ServerSelectDirectory()`, whose body calls the already emitted `ReleaseOwnedBuffers()` method before automatic destruction of its 32 entries. Its declaration is therefore present once in `Config.h`; the complete directory and entry type declarations remain owned by this class page's enclosing `Config` formal header.
- [UID:00028Q][0x0067a7c8-0x0067a7cc.g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md) emits the single zero-initialized `Config *g_pConfig` definition. `Config.h` retains only the matching `extern` declaration.

## UID0000KA Physical Header Closure - 2026-08-15

The complete existing Config declaration has moved intact from the CPP formal channel to guarded `NexusTK/config/Config.h`; CPP now includes the sibling header before exact children. This makes `g_pConfig` and `m_doubleClickEnabled` physically visible to InventoryPane without a duplicate getter, proxy, class, field, or storage definition. All pre-existing Config layouts, members, behavior, ownership, and scores are unchanged.

## Status

- Confidence: strong for base config ownership, singleton lifecycle, modeled
  constructor/destructor boundaries, and placement in the lower-level config
  module.
- Proposed file: [UID:0000IE][Config](by-file/Config.md)
- Current generated target: `auto-generated/NexusTK/config/Config.cpp`
- Current ranges: constructor [UID:00030S][0x0048e550-0x0048e77a.ConfigConstructor](by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md)
  and deleting destructor [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md).
- Evidence basis: existing project documentation plus IDA-backed by-memory and
  by-file evidence; older generated-source names are retained only as search
  context.
- Autogen status: reconstructable class attached to the [UID:0000IE][Config](by-file/Config.md)
  file root at position `10`. First-draft C++ on this class page is still
  declaration/support-type oriented: it records the recovered source surface,
  helper names, and `ConfigFixedTableRow` support layout while the accepted
  method bodies for the fixed-table helpers live on [UID:00021Z][0x0048e310-0x0048e479.ConfigRawTableHelpers](by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md).
  Broad class data layout and exact original field spelling remain prose until
  final-source quality is reached.

## Responsibility

`Config` is the base in-memory client configuration object. It installs `g_pConfig`, initializes fixed settings rows, string/list members, the MIDI track-path list, LogData heap text, and the embedded config-entry array, then releases those same owned resources during destruction. `RegistryConfig` owns defaults, command-line normalization, registry load/save, and persistence of inherited fields; `ProfileStorage` is only a consumer of the profile/user-data slice.

## Field And Layout Notes

- `m_selectedProfileName[0x100]` at `+0x2912b8` is consumed directly by [UID:0004E0][0x0053f940-0x0053fd95.ProfileDialogConstructor](by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md). The constructor computes its wide length and, only when nonempty, inserts the text into the owned profile editor through `TextEditPane::InsertTextRange`; this is a read-only constructor consumer of the established field and does not change its owner, type, extent, or serialization contract.
- `m_midiTrackPaths` at `+0x2912b4` is a heap `List *` constructed by [UID:00030S][0x0048e550-0x0048e77a.ConfigConstructor](by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md) as `List(0x42, 0x10)`, meaning 66-byte entries and 16-entry pages.
- The entry record is inferred as `ConfigMidiTrackPathEntry`: one-byte selector, one byte reserved/alignment, and `wchar_t path[32]` at entry offset `+2`. The type/name are descriptive; the layout is supported by the constructor element size and [UID:00032I][0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers](by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md) lookup/setter behavior.
- RegistryConfig persistence reads/writes this inherited base Config field under the `Midi` subkey, but persistence does not make the field or private wrappers RegistryConfig-owned.
- `m_midiEnabled` at `+0x84c` / decimal `2124` is the low Config MIDI enable byte checked or updated by `MidiPlayer::EnableMidiPlayback`, `DisableMidiPlayback`, and `SelectTrack`. Prefer `m_midiEnabled` in current `MidiPlayer` draft code so it does not collide with the later MusicControlDialog/SoundManager cluster at `+0x291908..+0x291914`.
- Fixed-table support is now `ConfigCharacterServerMacroRow m_fixedConfigRows[100]` at `+0x4`, stride `0x6894`, with active count `m_fixedConfigRowCount` at `+0x28d9d4`. UID00021Z copies the local player name into `wchar_t[40]`, compares typed player/server text, appends, and resets selected/index plus primary/alternate macro fields. Historical empty-key, lookupKey/stateBlock/wideValueSet, and 20-wide-buffer wording is superseded.

Accepted fixed-table row layout for current source reconstruction:

| Row offset | Field | Meaning |
| ---: | --- | --- |
| `+0x0000` | `lookupKey.header` | Word cleared by reset. |
| `+0x0002` | `lookupKey.text[256]` | Compared against the zeroed local lookup key. |
| `+0x0202` | `serverName.header` | Word cleared by reset. |
| `+0x0204` | `serverName.text[256]` | Compared against `g_pApplication->currentServerName`. |
| `+0x0404` | `stateBlock[0x14]` | Cleared by vector/dword zeroing. |
| `+0x1840` | `wideValueSetA[20]` | Cleared by the inner reset loop. |
| `+0x4068` | `wideValueSetB[20]` | Cleared by the inner reset loop. |
| `+0x6890` | `trailingStateValue` | Cleared before row advance. |

- The embedded `ServerSelectDirectory m_serverDirectory` starts at `+0x28db10`. Its 32 entries occupy 0x300 bytes, `entryCount` is at object `+0x28de10`, `version` is at `+0x28de14`, and the next `m_loginServerAddress` member begins at `+0x28de18`. Older `ConfigEntryBlock`, `+0x28dbd0`, count/dirty, and state-byte wording is retained only as historical search context.
- `ServerSelectEntry` is exactly 0x18 bytes: `unsigned char serverId` at `+0x00`; `wchar_t *name`, `*description`, and `*agreementText` at `+0x04/+0x08/+0x0c`; `unsigned char address[4]` at `+0x10`; and `unsigned short port` at `+0x14`. Natural x86 alignment supplies the unobserved padding; no source-visible reserved member is required.
- [UID:00032D][0x0048e480-0x0048e4a8.ConfigEntryInitialize](by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md) is the `ServerSelectEntry::ServerSelectEntry()` constructor callback. It initializes only the semantic fields and leaves natural padding unwritten.
- [UID:00032E][0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers](by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md) models two explicit cleanup bodies: `ServerSelectEntry::~ServerSelectEntry()` at `0x0048e4b0` and the direct scratch-entry cleanup helper at `0x0048e500`. Both free `name`, `description`, and `agreementText` in field order and clear them in reverse order.
- `+0x28de18` is the source-facing ANSI `m_loginServerAddress` member constructed by `sub_582A80` and destroyed by `sub_582B30`. Earlier helper-only passes left its semantics open; that unresolved wording is historical and superseded by the accepted complete Config layout.
- `+0x2911e0` is `mystr::StringBase<wchar_t> m_friendNames[20]`, the fixed-capacity friend-name array serialized by the Socket friend-list sender and destroyed by the Config destructor. Older generic string-handle and `+0x291060` wording is historical.
- `+0x291230` is `m_serverEndpointText[64]` for ServerSelect formatting. `m_musicFolderPath` is separate at `+0x29190c`; historical MP3Dir-at-endpoint wording is superseded.
- `+0x2916cc` is `m_logDataText` / registry `LogData`, an owned heap wide string replaced by [UID:00032I][0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers](by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md).
- `+0x2918f0` is `mystr::StringBase<wchar_t> m_startupLauncherId`: [UID:0002BR][0x004918e0-0x00491b28.StructuredHostPortIdLauncherParser](by-memory/0x004918e0-0x00491b28.StructuredHostPortIdLauncherParser.md) assigns the trimmed `/id:` token here. `m_clientVersionJitterEnabled` follows at `+0x2918f8`; the broader block-list/music-control cluster remains at `+0x2918fc`, `+0x29190c`, and `+0x291915..+0x291917`.
- `+0x291914` is `unsigned char m_soundFrequency`, persisted under registry key `SoundFreq`. MusicControlDialog uses `0` for disabled/muted, `1` for `22050` Hz, and `2` for `44100` Hz; SoundManager constructor/reinitialization consume the same byte. The former `m_musicOutputSelection` label is historical. This one-member source rename does not authorize an IDA Config UDT split: current analysis still represents `+0x29190c..+0x291917` as `_configTail[12]`, and the documented following members `m_showMiniMapPortals`, `m_showMiniMapNpcs`, and `m_showMiniMapPartyMembers` at `+0x291915/+0x291916/+0x291917` must remain intact.
- Rejected historical labels: `m_configEntryVector` for `+0x2912b4`, `m_registryEntries` for the MIDI list, `+0x28dbd0` for the embedded block, `+0x291060` for the 20 string handles, and `+0x2913b4` as the MIDI list pointer. These remain useful only as search context.

## Methods

| Address | Method | Role |
| --- | --- | --- |
| [UID:00030S][0x0048e550-0x0048e77a.ConfigConstructor](by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md) | `Config::Config()` | Constructs the base object, installs `g_pConfig`, initializes the 100-row fixed settings table, constructs 32 `ServerSelectEntry` records, initializes list/string storage, and clears display/file-name buffers. |
| [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md) | `virtual ~Config()` / scalar deleting destructor wrapper | The by-memory range is the MSVC scalar deleting destructor entry carrying the ordinary `Config::~Config` body. Source should declare/implement `virtual ~Config()`, not a hand-written `DeletingDestructor(unsigned int)` API. |
| [UID:0003FU][0x006168d0-0x006168e4.ConfigVtableData](by-memory/0x006168d0-0x006168e4.ConfigVtableData.md) | `virtual void SaveToRegistry() = 0;` / `virtual bool LoadFromRegistry() = 0;` | Base persistence slots at `0x006168dc` and `0x006168e0` resolve to `__purecall`; [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md) supplies the concrete overrides. [UID:0002H1][0x00464a60-0x00464cc1.ApplicationShutdown](by-memory/0x00464a60-0x00464cc1.ApplicationShutdown.md) calls `g_pConfig->SaveToRegistry()` before deleting the singleton. |
| [UID:00032H][0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw](by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md) | `Config::CopyMidiTrackPathsTo(List *destination) const` / `Config::CopyMidiTrackPathsFrom(List *source)` | Retained private wrappers that copy `m_midiTrackPaths` to/from caller `List` objects through [UID:0003JT][0x004f3140-0x004f31cc.ListAssignFrom](by-memory/0x004f3140-0x004f31cc.ListAssignFrom.md). Names are descriptive/inferred because no direct caller route survives. |
| [UID:00032I][0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers](by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md) | `Config::GetMidiTrackPath`, `Config::SetMidiTrackPath`, `Config::SetLogData` | MIDI selector lookup/setter over 66-byte `m_midiTrackPaths` records, plus the `LogData` heap wide-string replacer at `+0x2916cc`. |

## UID0004E0 Selected-Profile Consumer

- [UID:0004E0][0x0053f940-0x0053fd95.ProfileDialogConstructor](by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md) is the exact constructor read path for `g_pConfig->m_selectedProfileName`. It preserves the field as `wchar_t[0x100]`, tests `wcslen(...) != 0`, and passes the same pointer plus narrowed length to the selected-profile text editor.
- The sibling [UID:0004E2][0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction](by-memory/0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction.md) remains the accepted write path, while ProfileStorage save/load and opcode-79 refresh remain persistence/network consumers. Constructor consumption adds an exact cross-reference but no new field, alias, UDT overlay, accessor, score, metadata, or formal-code change.

## Related Helpers

- [UID:00021Z][0x0048e310-0x0048e479.ConfigRawTableHelpers](by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md)
  covers the raw config-table lookup/append and reset helpers immediately
  before entry construction.
- [UID:00032D][0x0048e480-0x0048e4a8.ConfigEntryInitialize](by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md)
  initializes one 0x18-byte `ServerSelectEntry` record.
- [UID:00032E][0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers](by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md)
  covers the `ServerSelectEntry` destructor callback and direct scratch-entry cleanup helper, with exact `name`, `description`, and `agreementText` fields.
- [UID:00032H][0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw](by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md)
  covers retained private wrappers around the `m_midiTrackPaths` (`this + 0x2912b4`) MIDI track-path list helper.
- [UID:00032I][0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers](by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md)
  covers Config-owned MIDI track-path selector lookup/setter and heap-backed string preference
  helpers used by MIDI and UI/login/create-user callers through `g_pConfig`.
- [UID:000032][ConfigEntryBlock](by-class/ConfigEntryBlock.md) and
  [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md)
  cover embedded `ServerSelectDirectory` cleanup; `ConfigEntryBlock` is the historical documentation identity only.
- [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md) extends the same
  storage and owns registry-backed defaults/load/save.

## Evidence Notes

- [UID:0000IE][Config](by-file/Config.md) is the `NexusTK/config/` source root
  and keeps `Config`, private `ServerSelectEntry`/`ServerSelectDirectory`, raw
  config-table helpers, and entry construction/destruction in the lower-level
  configuration module.
- [UID:00030S][0x0048e550-0x0048e77a.ConfigConstructor](by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md)
  is an exact `87/90` constructor child assigned to this class after the mixed
  aggregate was split.
- [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md)
  is now a non-emitting mixed inventory over exact Config and RegistryConfig
  children. B001-015 split [UID:00032D][0x0048e480-0x0048e4a8.ConfigEntryInitialize](by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md), [UID:00032E][0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers](by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md), [UID:00032H][0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw](by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md), and
  [UID:00032I][0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers](by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md) out as Config-owned helper pages.
- [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md)
  records the exact vtable-dispatched deleting destructor, cleanup order,
  20-entry and 32-entry destructor passes, `g_pConfig` clear, scalar-delete
  flag handling, and now assigns directly here after the child reached `87/90`.
- [UID:00028Q][0x0067a7c8-0x0067a7cc.g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md)
  documents the process config singleton touched by the constructor and
  destructor.
- [UID:0003FU][0x006168d0-0x006168e4.ConfigVtableData](by-memory/0x006168d0-0x006168e4.ConfigVtableData.md)
  documents the exact `Config` vtable data split from the mixed
  Config/channel `.rdata` aggregate and attaches directly here.
- B010's accepted ApplicationCleanupResources implementation rechecked the base
  vtable bytes as `0x00494020`, `0x004f4b10`, `0x0041b6c0`,
  `0x005ca28c`, `0x005ca28c`, and `0x00000000`; `lookup_funcs`
  resolves `0x005ca28c` to `__purecall`. Those two pure virtual tail slots
  correspond to `SaveToRegistry` and `LoadFromRegistry`, with
  [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md) supplying the
  concrete implementations used by `g_pConfig`.

## UID0003UB Inherited Runtime Storage Audit

[UID:0003UB][0x005a3ae0-0x005a3d39.UserPaneExecuteHotkeyAction](by-memory/0x005a3ae0-0x005a3d39.UserPaneExecuteHotkeyAction.md) is a direct external consumer of Config storage. Its only merged key-handler caller supplies page bases `0`, `10`, or `20`; after decade rotation, the method reads one of 30 `0x108`-byte [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) rows at `g_pConfig + 0x28f2ec`. State is at row `+0x04`, `wchar_t[0x80]` payload is at row `+0x08`, and the method has no `g_pConfig` null guard. State `Text` sends opcode `0x0e`, subtype `0`, one-byte ACP text length, and exactly `textLength` payload bytes; states `Spell` and `Item` duplicate alphabetic mapping before one-based `UserPane::UseCommandSlot` and `UserPane::UseInventorySlot` calls.

The table belongs to inherited Config runtime storage, not a RegistryConfig-only tail. Application startup allocates exactly `0x291918` bytes, invokes `Config::Config`, and then patches the object to the RegistryConfig vtable. The Config constructor initializes storage on both sides of the table, including the `+0x2911e0` string-handle group and later high members; `RegistryConfig::InitializeUserDataDefaults`, profile load/save, macro dialogs, and UserPane all agree on row base, stride, state, and payload. `g_pConfig` remains source-typed as `Config *`, while the runtime object is RegistryConfig.

Historical UID0003UB-era analysis below exhaustively rejected nested-profile, RegistryConfig-only, derived-cast, raw/accessor, field-only, and placeholder-heavy declaration routes. Its no-complete-declaration conclusion is superseded by the accepted typed layout, while the rejection evidence remains valid provenance:

- `m_userProfile.m_macroHotkeyRecords`, because no nested aggregate declaration or access boundary is supported;
- a RegistryConfig field or explicit derived cast, because construction proves the storage is inherited from Config;
- direct `g_pConfig->m_macroHotkeys` without a complete preceding layout;
- raw-offset/reinterpret accessors and unobserved out-of-line accessors, because the target contains no such call and those shapes are decompiler/layout scaffolding;
- a field-only partial Config declaration, which would place the table at the wrong offset;
- a purported full Config layout filled with `m_unresolved*`, generic `reserved*`, or giant opaque arrays.

Historical pre-callback blockers identified the fixed-row interiors, launcher overlay, ANSI login field, endpoint/music conflict, and high storage correctly, but they are now resolved by typed character/server macro rows, the protocol-view launcher union, `m_loginServerAddress`, the endpoint/music split, semantic option/profile storage, and exact object size. The current formal block is complete at `90/92`; UID0003UB's separate target formal disposition is not modified here.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `94` | The complete class/source boundary, exact `0x291918` layout, all later accepted storage contracts, and the exact natural-aligned `ServerSelectEntry`/`ServerSelectDirectory` declarations are documented in the sole owning formal channel. |
| Confidence `95` | Constructors/destructors, registry load/save, packet population, ServerSelect consumers, and the full existing Config evidence agree on exact offsets, widths, container shapes, and natural alignment. Original private spellings and header partition remain confidence caps. |

## Cross-References

- [UID:0000IE][Config](by-file/Config.md)
- [UID:0004E0][0x0053f940-0x0053fd95.ProfileDialogConstructor](by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md)
- [UID:00021Z][0x0048e310-0x0048e479.ConfigRawTableHelpers](by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md)
- [UID:00032D][0x0048e480-0x0048e4a8.ConfigEntryInitialize](by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md)
- [UID:00032E][0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers](by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md)
- [UID:00030S][0x0048e550-0x0048e77a.ConfigConstructor](by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md)
- [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md)
- [UID:00032H][0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw](by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md)
- [UID:00032I][0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers](by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md)
- [UID:0003JT][0x004f3140-0x004f31cc.ListAssignFrom](by-memory/0x004f3140-0x004f31cc.ListAssignFrom.md)
- [UID:000111][0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md)
- [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md)
- [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md)
- [UID:00028Q][0x0067a7c8-0x0067a7cc.g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md)
- [UID:0003FU][0x006168d0-0x006168e4.ConfigVtableData](by-memory/0x006168d0-0x006168e4.ConfigVtableData.md)

## 2026-07-29 Supervisor Gate 2B Reconciliation (Catalog 0353)

- I11 was verified as an intentional no-change action. The protected IDA `Config` UDT remains exactly size `0x291918` with `51` members and `_configTail[12]` unchanged at `+0x29190c`; no synthetic members were written at `+0x291915`, `+0x291916`, or `+0x291917`.
- The documented source members `m_showMiniMapPortals`, `m_showMiniMapNpcs`, and `m_showMiniMapPartyMembers` therefore remain protected documentation evidence rather than an unsafe partial IDA overlay. All report-listed Config names, types, offsets, and sizes read back unchanged.
- Persistence checkpoint for the surrounding accepted Gate 2B batch: prestate IDB SHA256 `FD8282A51836D47961EA386D7C2D25F80D0BF88B96ACFF106FFA802277F78B16`; byte-identical backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B010-UID0003MQ-20260729-082218.i64`; saved IDB SHA256 `6D20767D448CC568508E462790D05678838216C6CFEE77E3CFF5C4B5905244AB`, `143190049` bytes, `2026-07-29T08:26:09.5759690-04:00`. Catalog entry `0353` is `APPLIED_VERIFIED_RECONCILIATION_PENDING`; B010 did not mutate IDA.

## UID0000MV Socket Consumer Layout Synchronization - 2026-08-17

- The complete formal header includes `../util/StringBase.h` for canonical `mystr::StringBase` objects and `../util/StringUtil.h` for the embedded complete `SimpleUStringVector`. This replaces incomplete unqualified/forward-only dependencies without introducing a second template/vector declaration or storage owner.
- The twenty `mystr::StringBase<wchar_t>` objects beginning at `Config+0x2911e0` are the fixed-capacity friend-name array consumed by the Socket friend-list sender. The source-facing member is therefore `m_friendNames[20]`, not the older generic `m_profileStringSlots` label; construction, destruction, profile persistence, and packet serialization continue to use the same exact storage.
- `m_clientVersionJitterEnabled` is the one-byte Config flag at `+0x2918f8` read by `Socket::QueueClientVersionStatusPacket`. It occupies the previously unnamed alignment byte after `m_soundLatency`; natural alignment still places `m_systemHelperFlags` at `+0x2918fa`, `m_blockListenNames` at `+0x2918fc`, and preserves exact `sizeof(Config)==0x291918`.
- No duplicate Config storage, accessor, packet helper, derived overlay, explicit padding member, or object-size change is introduced. Completion/confidence remain `94/95` because this callback resolves source-facing names and an already bounded byte while preserving the established complete layout.

## Changes

- 2026-08-24 B003 UID0000IF C138 support callback:
  - Added the direct `../util/StringUtil.h` include after `StringBase.h` and removed only the insufficient `class SimpleUStringVector;` forward declaration.
  - Preserved every Config support type, field, offset, class/API declaration, owner/emitter, score, formal CPP, exact `0x291918` layout, and unrelated history. The complete type remains owned once by UID0000DA through UID0000OB.

- 2026-08-17 B003 UID0000MV accepted ordinary callback:
  - Qualified the embedded string members through canonical `mystr::StringBase`, renamed the exact 20-entry `+0x2911e0` storage to `m_friendNames`, and declared `m_clientVersionJitterEnabled` at `+0x2918f8` in the former natural-alignment byte.
  - Preserved every following offset, exact `0x291918` object size, owner/emitter, score, method body, and unrelated layout/history detail.

- 2026-08-15 B007 UID000480 accepted support callback:
  - Kept `94/95`, owner/emitter [UID:0000IE][Config](by-file/Config.md), reconstructable state, formal CPP children, and the complete existing H declaration.
  - Added complete LObject/Singleton includes, direct `Singleton<Config>` inheritance, removed the invalid LObject forward declaration, and documented exact UID000535/UID0003FU/padding and lifecycle evidence without pruning layout detail.

- 2026-08-01 B006 UID0004E0 support callback: preserved `92/93`, complete `0x291918` formal layout, owner/emitter UID0000IE, all code, and all established field lifecycles. Added only the exact ProfileDialog constructor read cross-reference for `m_selectedProfileName[0x100]` at `+0x2912b8`, including guarded nonempty `InsertTextRange` behavior and an explicit no-layout/no-score/no-code-change disposition.

- 2026-07-29 B010 MusicControlDialog support callback: replaced only `m_musicOutputSelection` with `m_soundFrequency` in the formal Config declaration, documented the `SoundFreq` 0/22050/44100-Hz contract, and explicitly preserved the three following minimap members plus the protected unsplit IDA `_configTail[12]`. Score remains `92/93`.
- 2026-07-06 B011 UID00032D implementation callback support sync:
  - Score unchanged. Added the constructor-specific ConfigEntry note that [UID:00032D][0x0048e480-0x0048e4a8.ConfigEntryInitialize](by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md) initializes selector, three text pointers, value, state, and flags only.
  - Summary/evidence: B011 UID00032D target implementation corrects the old padding implication; `reserved0[3]` and `reserved1` remain declaration-layout storage but are not proven initialized by `ConfigEntry::ConfigEntry()`.
- 2026-07-06 B001 UID00032E implementation callback support sync:
  - Score unchanged at `87/89`.
  - Summary/evidence: aligned the ConfigEntry layout notes with [UID:00032E][0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers](by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md), which now models two explicit cleanup bodies for the destructor callback and direct helper. The class declaration keeps descriptive `primaryText`, `secondaryText`, and `tertiaryText` fields; exact original field/helper spelling remains a target-level confidence cap.
- 2026-06-29 B010 ApplicationCleanupResources support implementation:
  - Score unchanged. Added declaration-level persistence virtuals `virtual void SaveToRegistry() = 0;` and `virtual bool LoadFromRegistry() = 0;` to the formal `Config` class block and method inventory.
  - Summary/evidence: accepted B010 report for [UID:0002H1][0x00464a60-0x00464cc1.ApplicationShutdown](by-memory/0x00464a60-0x00464cc1.ApplicationShutdown.md) resolved the cleanup vtable slot `+0x0c` by comparing [UID:0003FU][0x006168d0-0x006168e4.ConfigVtableData](by-memory/0x006168d0-0x006168e4.ConfigVtableData.md) base purecall tail slots with [UID:000481][0x00612614-0x00612628.RegistryConfigVtableData](by-memory/0x00612614-0x00612628.RegistryConfigVtableData.md) derived slots `0x00491b30` / `0x004926a0`. H1 now calls `g_pConfig->SaveToRegistry()` before deleting the singleton.

- 2026-06-27 B011 [UID:0002BR][0x004918e0-0x00491b28.StructuredHostPortIdLauncherParser](by-memory/0x004918e0-0x00491b28.StructuredHostPortIdLauncherParser.md) implementation callback support sync:
  - Score unchanged. Revised `+0x2918f0` from block-list/music-control-only wording to include this target's StringBase-style structured launcher id storage, inferred as `m_startupLauncherId` in the child C++.
  - Evidence: B011 MCP session `398b87c1` confirms [UID:0002BR][0x004918e0-0x00491b28.StructuredHostPortIdLauncherParser](by-memory/0x004918e0-0x00491b28.StructuredHostPortIdLauncherParser.md) extracts `/id:`, trims it, and assigns it to `this + 0x2918f0`; broader block-list/music-control caveats remain preserved.
- 2026-06-06 parent attachment update:
  - Before: the page was `72/84`, reconstructable, but unassigned because it
    still failed the child-side parent gate and retained stale generated-source
    provenance.
  - After: raised to `82/86`, attached to [UID:0000IE][Config](by-file/Config.md)
    at position `10`, replaced stale provenance with project-doc/IDA-backed
    evidence, added evidence notes and score rationale, and kept C++ blank under
    the final-source gate.
  - Evidence: [UID:0000IE][Config](by-file/Config.md) is an `86/84` file root
    under `NexusTK/config/`; [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md)
    documents the constructor/defaults side; [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md)
    documents the exact destructor cleanup; and [UID:00028Q][0x0067a7c8-0x0067a7cc.g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md)
    anchors singleton ownership.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/84`.
  - Summary/evidence: constructor/destructor responsibility, global ownership, member initialization/release behavior, and related helper ranges are documented; remaining work is detailed member layout, exact original type names, and fuller generated-C++ reconstruction.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains blank because the class completion score is below the 80% attachment gate.
  - Evidence: live IDA MCP confirms modeled function starts at `0x0048e550` and `0x00494020`, with config construction called from startup/config initialization at `0x00464136`; existing project docs place the class in [UID:0000IE][Config](by-file/Config.md).
- 2026-06-08 A010 Batch112: Raised completion from `82` to `85` and kept confidence at `86`.
  - Before: the constructor was only linked through the mixed Config/RegistryConfig aggregate, so this class did not fully support the strict direct-child gate for a constructor page.
  - After: linked exact child [UID:00030S][0x0048e550-0x0048e77a.ConfigConstructor](by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md) and updated the file parent evidence to [UID:0000IE][Config](by-file/Config.md) `86/85`.
  - Evidence: the constructor child isolates `Config::Config`, singleton installation, fixed settings initialization, config-entry construction, and destructor partner evidence while leaving final C++ blank below the 95/95 gate.
- 2026-06-08 A010 Batch120 child-routing repair:
  - Changed to: no score change.
  - Summary/evidence: [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md) now attaches directly to this class after reaching `85/88`. This class remains `85/86` and the file parent [UID:0000IE][Config](by-file/Config.md) remains `86/85`, satisfying the corrected gate without changing final-source readiness.
- 2026-06-10 B001-015 split repair:
  - Changed to: no score change.
  - Summary/evidence: exact Config-owned helper children [UID:00032D][0x0048e480-0x0048e4a8.ConfigEntryInitialize](by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md), [UID:00032E][0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers](by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md), [UID:00032H][0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw](by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md), and [UID:00032I][0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers](by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md) now carry the base Config storage/preference helper evidence that used to be trapped in the mixed aggregate.
- 2026-06-19 B005 Rule 26 source-quality incorporation:
  - Changed to: completion `86`, confidence `88`.
  - Summary/evidence: added the `m_midiTrackPaths` field/layout note, the inferred `ConfigMidiTrackPathEntry` shape, and private copy-wrapper methods from [UID:00032H][0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw](by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md). The class C++ stays blank because broader Config declarations and destructor/source split are not final-source quality.
- 2026-06-21 B006 MidiPlayer support sync:
  - Score unchanged.
  - Summary/evidence: added low Config field `m_midiEnabled` at `+0x84c` / decimal `2124` as the MIDI enable flag consumed by the `MidiPlayer` select/toggle helpers.
- 2026-06-21 B012 Rule 26 Config source-quality pass:
  - Changed from `86/88` to `87/89`.
  - Summary/evidence: added declaration-only first-draft C++, corrected the ConfigEntryBlock base to `+0x28db10`, count/dirty to `+0x28de10/+0x28de14`, the 20 string-handle array to `+0x2911e0`, MP3/music directory to `+0x291230`, `m_midiTrackPaths` to `+0x2912b4`, and `m_logDataText` / `LogData` to `+0x2916cc`; documented the fixed-table helper names, scalar-deleting-destructor policy, ConfigEntry layout, MIDI path record shape, and rejected stale `ConfigEntryVector`, `+0x28dbd0`, `+0x291060`, and `+0x2913b4` wording.
- 2026-06-26 B007 ConfigRawTableHelpers support sync:
  - Score unchanged.
  - Summary/evidence: added the accepted `ConfigFixedTableText` / `ConfigFixedTableRow` support declarations, synchronized the fixed row slab start at `+0x4`, stride `0x6894`, 100-row count at `+0x28d9d4`, row field meanings, corrected 20-wide-character / 40-byte local lookup buffer, and accepted helper C++ readiness. The raw helper no-route/original-name uncertainty remains documented as a score cap rather than a reason to keep the target C++ blank.
- 2026-07-15 B005 UID0003UB callback synchronization:
  - Score, owner/emitter/position, reconstructable state, and the existing formal block remain unchanged at `87/89`.
  - Added the exact inherited macro-table runtime consumer, startup allocation/Config-construction/RegistryConfig-vtable sequence, fixed-row and high-storage declaration evidence, and exhaustive rejection of nested-profile, RegistryConfig-cast, undeclared-member, raw-accessor, partial-layout, and placeholder-heavy full-layout source routes. UID0003UB remains a retained blank-formal/no-body emitter.

## 2026-07-15 UID0003UP Complete Config Layout Callback

### Applied declaration and source boundary

- The accepted callback replaces the former data-member-free/placeholder-heavy partial shell with the complete source-era x86/MSVC `Config` declaration used by every emitted `Config::` definition. `Config` remains an `LObject`-derived base object owned/emitted by UID0000IE; existing methods, children, ownership, and unrelated history remain intact.
- The declaration spans exact `sizeof(Config)==0x291918`. It uses typed active members, an anonymous launcher-protocol union, descriptive semantic option/profile fields, and compiler-natural alignment. It emits no raw offset, explicit padding/reserved array, `m_unresolved*`, opaque byte wrapper, numeric slot/type label, schematic A/B field, RegistryConfig downcast, or decompiler scaffolding.
- Canonical `mystr::StringBase`, `SimpleUStringVector`, and `LObject` declarations remain external dependencies; the formal header includes `StringBase.h` and `StringUtil.h` for embedded complete objects, while `List` remains pointer-only. No duplicate template/vector declaration or implementation is introduced.

### Exact support types and cumulative layout

- `ConfigFixedTableText` is `0x202`; `CompactShortcutRecord` is `0x4`; `MacroHotkeyRecord` is `0x108` with natural alignment at state; each `ConfigCharacterServerMacroRow` is `0x6894`; the 100-row slab begins at `+0x4`; and `m_fixedConfigRowCount` is `+0x28d9d4`.
- Exact cumulative offsets are: launcher union/`m_thrunetAuthenticationToken=+0x28d9e0`; `m_serverDirectory=+0x28db10`; `m_loginServerAddress=+0x28de18`; `m_startupConnectionMode=+0x28de28`; `m_fontIndex=+0x28de30`; `m_adapterPhysicalAddressDigest=+0x28de38`; `m_soundEffectsEnabled=+0x28de48`; `m_mapEffectEnabled=+0x28de58`; `m_staticObjectTransparencyEnabled=+0x28de5d`; `m_showUserName=+0x28de5f`; `m_selfLookTopButtonSelected=+0x28de60`; `m_selfLookBottomButtonSelected=+0x28de61`; `m_graphicsSetting=+0x28de68`; `m_hearSnoreMode=+0x28de71`; and `m_mapMovementStatusOption=+0x28de75`.
- High storage continues with `m_profileTextSlots=+0x28de9c`, `m_macroHotkeys=+0x28f2ec`, `m_friendNames=+0x2911e0`, `m_serverEndpointText=+0x291230`, `m_midiTrackPaths=+0x2912b4`, `m_startupAddress=+0x2915b4`, startup port/token union `+0x2916c4`, `m_logDataText=+0x2916cc`, `m_clientVersionJitterEnabled=+0x2918f8`, `m_blockListenNames=+0x2918fc`, `m_musicFolderPath=+0x29190c`, and exact end `0x291918`.
- Natural x86/MSVC padding alone accounts for `+0x28d9de..df`, `+0x28de33`, `+0x28de49..4b`, `+0x28de51..53`, `+0x28de67`, and `+0x2918f9`; `m_systemHelperFlags` remains naturally aligned at `+0x2918fa`.

### Field and container evidence

- Constructor/destructor, defaults, registry load/save, launcher parsers, OptionPane controls, Ctrl+T, renderer, SelfLook, profile serialization, startup/server selection, music, and movement consumers jointly prove the active layout.
- The `+0x28d9e0..+0x28db10` storage is an aligned anonymous union of Thrunet token `[64]`, LG session id/key `[64]`, Generic/Bixel payload `[2][64]`, `ILauncherAuthentication *`, and Kornet World `[3][16]` plus `[256]`; its size is `0x130` and the following server directory remains exact.
- `m_loginServerAddress` is the ANSI login endpoint at `+0x28de18`, distinct from later `m_serverEndpointText[64]`. `m_musicFolderPath` is the final music directory at `+0x29190c`; the old MP3-at-`+0x291230` claim is superseded.
- The movement family directly reads and writes one arbitrary unsigned byte, `m_mapMovementStatusOption`, at `+0x28de75`. Defaults, UI/server writers, and movement consumers rank direct base storage above an accessor, nested aggregate, alias union, separate global, or derived cast.
- Typed character/server macro rows preserve player/server identity, primary/alternate macro fields, 20-row bank semantics, and fixed-row helper behavior. Profile/high storage preserves ten fixed wchar rows, legacy first-wchar values, twenty pointer-backed strings, selected profile text, block-list vector, compact shortcuts, thirty macro hotkeys, startup state, MIDI paths, and minimap flags.

### Historical and negative evidence

- UID0003UB's earlier exhaustive objection to an undeclared derived-only macro field remains valid history; this callback resolves it by declaring the complete base storage rather than reviving a RegistryConfig cast.
- B012/B007 partial layouts, explicit `reserved` spans, empty-key/schematic fixed-row models, numeric options, opaque launcher wrappers, and incomplete endpoint/music interpretations are historicalized and rejected as current source shape.
- Exact original private spellings for some protocol payloads and option gameplay labels remain lexical confidence caps only. Every retained descriptive name maps to bounded behavior; no source dependency or layout interval remains unresolved.

## 2026-07-15 UID0003UA Compact Shortcut Contract Synchronization

- This bounded class rebase was applied after rereading the terminal B005 UID0003UP artifact, terminal B002 UID0003H5 artifact, and the live Config declaration under the short lease. It preserves B005's complete x86/MSVC `Config` class, launcher-protocol union, all fixed-row/profile/option/startup/music fields, exact natural alignment, every emitted-method dependency, `sizeof(Config)==0x291918`, score `90/92`, canonical owner/emitter UID0000IE, and all unrelated current and historical evidence.
- The exact 20-row compact table begins at `Config+0x28f29c`, has 0x4-byte stride, and uses `CompactShortcutRecord { wchar_t code; unsigned char isSpellMode; }` plus one byte of compiler-natural tail alignment. The one-byte source identifier change from `mode` to `isSpellMode` is size- and offset-neutral and makes the declaration agree with RegistryConfig default/load/save, ProfileStorage, MacroDialogs, and UserPane consumers.
- [UID:0003UA][0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey](by-memory/0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey.md) accesses this table directly through base-typed `g_pConfig`. It reads `code`, classifies the sign-extended low byte, and treats `isSpellMode` as an arbitrary byte whose nonzero state selects `UseCommandSlot` and whose zero state selects `UseInventorySlot`; no `bool` narrowing is asserted.
- Lifecycle evidence is cumulative and exact: defaults initialize each row's `code` and `isSpellMode`; profile load/migration/save read and write the same two fields; NewMacroDialog constructor/save/load use the same row contract; no constructor, destructor, copy, persistence, or runtime path touches the tail byte. The final byte is therefore natural alignment, not a named flag, reserved source member, packed overlay, or separate profile field.
- Historical `m_userProfile.m_compactShortcutRecords`, RegistryConfig casts, raw `+0x28f29c` accessors, opaque rows, `key/mode`, `wchar_t/bool`, explicit padding members, partial class shells, and declarations that left emitted Config methods without fields remain rejected. Exact private lexical naming is confidence-capped, but width, order, base ownership, lifecycle, direct access, source route, and layout are resolved.
- The managed declaration now matches report Destination R2 exactly. No unrelated Config formal byte, method, score, route, position, inheritance, union arm, object boundary, or source/compiler disposition changed.

## B001 UID0003FV Accepted Callback Synchronization - 2026-07-20

- Final class state is `92/93`, owner/emitter UID0000IE Config, reconstructable, and positionless. The complete accepted declaration remains a single managed class block with the class-closing brace before any child marker.
- The object allocation is exactly `0x291918` bytes. The public late-layout startup fields retain their current cumulative offsets, and public `RegistryConfig : public Config` inheritance makes all parser access source-legal without friend declarations, accessors, raw-offset expressions, or a duplicate declaration.
- The protocol overlay at `+0x28d9e0` now uses `ILauncherAuthenticationPtr *m_launcherAuthenticationObject`. This is a pointer to the four-byte COM smart-pointer holder allocated by UID0002BN, not a direct `ILauncherAuthentication *`; all other union views and the complete B005-established Config layout remain unchanged.
- The startup connection mode, address, host, port/token, server-id, ready, log, launcher-id, sound, list, and music fields preserve their accepted types, order, natural alignment, and source-facing names. No universal protocol-union constructor or cleanup is invented because each selected parser initializes its own overlay and the observed destructors do not release the launcher holder.
- Source declarations for vendor COM interfaces remain consumer-local where their complete ABI is needed. This shared class route keeps only the forward declaration and smart-pointer typedef dependency required for the member type, avoiding duplicate COM bodies and target-owned GUID storage.
- Historical direct-interface-pointer wording is superseded by the allocation/store/QueryInterface evidence in UID0002BN. The correction is bounded to holder indirection and does not replace or compress the complete current cross-agent Config union.

## 2026-08-10 B010 UID0002PA Accepted Callback Synchronization

- Final class state is `94/95`; owner/emitter UID0000IE, reconstructable state, and the complete later accepted `Config` layout remain unchanged.
- The sole owning formal CPP channel now declares exact natural-aligned `ServerSelectEntry` and `ServerSelectDirectory` types and types `m_serverDirectory` accordingly. The declaration preserves `sizeof(ServerSelectEntry)==0x18`, directory size `0x308`, `m_serverDirectory` at `+0x28db10`, and the following `m_loginServerAddress` boundary at `+0x28de18` without explicit padding members.
- Generic `ConfigEntry`/`ConfigEntryBlock`, selector/primary/secondary/tertiary, value/state/flags, count/dirty, explicit-reserved, separate-ConfigEntry.cpp, and null-safe cleanup assumptions remain preserved in dated historical text but are rejected as current source authority.
