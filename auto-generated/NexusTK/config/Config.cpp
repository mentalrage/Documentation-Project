// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IE
// Source by-file doc: by-file/Config.md
// UID:000031 | by-class/Config.md | Completion:94 | Confidence:95
#include "Config.h"
#include "../util/List.h"

// UID:00030S | by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md | Completion:87 | Confidence:90
Config::Config()
{
    m_serverDirectory.entryCount = 0;
    m_serverDirectory.version = 0;

    m_midiTrackPaths = new List(0x42, 0x10);
    m_logDataText = 0;

    memset(m_startupAddress, 0, 4);
    m_startupPort = 0;
    m_systemHelperFlags = 0;

    wcscpy_s(m_serverEndpointText, _countof(m_serverEndpointText), L"");
    wcscpy_s(m_lastServerName, _countof(m_lastServerName), L"");

    m_showMiniMapPortals = 1;
    m_showMiniMapNpcs = 1;
    m_showMiniMapPartyMembers = 0;

    for (int rowIndex = 0; rowIndex < 100; ++rowIndex)
    {
        ConfigCharacterServerMacroRow &row = m_fixedConfigRows[rowIndex];
        row.playerName.length = 0;
        row.serverName.length = 0;

        for (int macroIndex = 0; macroIndex < 20; ++macroIndex)
        {
            row.macroEnabled[macroIndex] = 0;
            row.primaryMacroKeys[macroIndex] = 0;
            row.alternateMacroKeys[macroIndex] = 0;
        }

        row.selectedMacroIndex = 0;
    }
}

// UID:0002P9 | by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md | Completion:87 | Confidence:90
Config::~Config()
{
    delete m_midiTrackPaths;
    m_midiTrackPaths = 0;

    free(m_logDataText);
}

// UID:000535 | by-memory/0x006168cc-0x006168d0.ConfigRttiLocatorPointer.md | Completion:92 | Confidence:95
// Compiler-generated MSVC RTTI complete-object-locator pointer for Config.
// The Config class declaration regenerates this primary vftable[-1] metadata.
// No standalone source object or raw RTTI dword is emitted here.

// UID:0003FU | by-memory/0x006168d0-0x006168e4.ConfigVtableData.md | Completion:92 | Confidence:95
// Compiler-generated MSVC primary vtable for Config.
// The Config virtual declaration regenerates these five slots.
// No standalone source array or raw vtable dword table is emitted here.

// UID:000032 | by-class/ConfigEntryBlock.md | Completion:92 | Confidence:94
ServerSelectDirectory::~ServerSelectDirectory()
{
    ReleaseOwnedBuffers();
}

// UID:00021Z | by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md | Completion:88 | Confidence:90
int Config::FindOrAppendFixedConfigTableRow()
{
    wchar_t playerName[40];
    GetLocalPlayerName(playerName, _countof(playerName));

    int rowCount = m_fixedConfigRowCount;
    int rowIndex = 0;

    if (rowCount > 0)
    {
        ConfigCharacterServerMacroRow *row = m_fixedConfigRows;
        const wchar_t *currentServerName = g_pApplication->currentServerName;

        do
        {
            if (wcscmp(row->playerName.text, playerName) == 0 &&
                wcscmp(row->serverName.text, currentServerName) == 0)
            {
                return rowIndex;
            }

            ++rowIndex;
            ++row;
            rowCount = m_fixedConfigRowCount;
        }
        while (rowIndex < rowCount);
    }

    m_fixedConfigRowCount = rowCount + 1;
    return rowIndex;
}

void Config::ResetFixedConfigTableRows()
{
    for (int rowIndex = 0; rowIndex < 100; ++rowIndex)
    {
        ConfigCharacterServerMacroRow &row = m_fixedConfigRows[rowIndex];

        row.playerName.length = 0;
        row.serverName.length = 0;
        memset(row.macroEnabled, 0, sizeof(row.macroEnabled));

        for (int macroIndex = 0; macroIndex < 20; ++macroIndex)
        {
            row.primaryMacroKeys[macroIndex] = 0;
            row.alternateMacroKeys[macroIndex] = 0;
        }

        row.selectedMacroIndex = 0;
    }
}

// UID:00032D | by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md | Completion:92 | Confidence:94
ServerSelectEntry::ServerSelectEntry()
{
    serverId = 0;
    name = 0;
    description = 0;
    agreementText = 0;
    address[0] = 0;
    address[1] = 0;
    address[2] = 0;
    address[3] = 0;
    port = 0;
}

// UID:00032E | by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md | Completion:92 | Confidence:94
ServerSelectEntry::~ServerSelectEntry()
{
    if (name != 0)
    {
        free(name);
    }

    if (description != 0)
    {
        free(description);
    }

    if (agreementText != 0)
    {
        free(agreementText);
    }

    agreementText = 0;
    description = 0;
    name = 0;
}

void ReleaseServerSelectEntryOwnedBuffers(ServerSelectEntry *entry)
{
    if (entry->name != 0)
    {
        free(entry->name);
    }

    if (entry->description != 0)
    {
        free(entry->description);
    }

    if (entry->agreementText != 0)
    {
        free(entry->agreementText);
    }

    entry->agreementText = 0;
    entry->description = 0;
    entry->name = 0;
}

// UID:00032H | by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md | Completion:88 | Confidence:90
void Config::CopyMidiTrackPathsTo(List *destination) const
{
    destination->AssignFrom(m_midiTrackPaths);
}

void Config::CopyMidiTrackPathsFrom(List *source)
{
    m_midiTrackPaths->AssignFrom(source);
}

// UID:00032I | by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md | Completion:88 | Confidence:90
void Config::GetMidiTrackPath(unsigned char selector, wchar_t *destination, size_t destinationCount) const
{
    if (destination == 0 || destinationCount == 0)
        return;

    destination[0] = L'\0';

    for (int index = 0; index < m_midiTrackPaths->m_count; ++index)
    {
        ConfigMidiTrackPathEntry *entry =
            static_cast<ConfigMidiTrackPathEntry *>(m_midiTrackPaths->GetElementAt(index));

        if (entry != 0 && entry->selector == selector)
        {
            _wcscpy_s(destination, destinationCount, entry->path);
            return;
        }
    }
}

void Config::SetMidiTrackPath(unsigned char selector, const wchar_t *source)
{
    for (int index = 0; index < m_midiTrackPaths->m_count; ++index)
    {
        ConfigMidiTrackPathEntry *entry =
            static_cast<ConfigMidiTrackPathEntry *>(m_midiTrackPaths->GetElementAt(index));

        if (entry != 0 && entry->selector == selector)
        {
            _wcscpy_s(entry->path, 32, source != 0 ? source : L"");
            return;
        }
    }
}

void Config::SetLogData(const wchar_t *source)
{
    if (m_logDataText != 0)
    {
        free(m_logDataText);
        m_logDataText = 0;
    }

    if (source == 0)
        source = L"";

    size_t characterCount = wcslen(source) + 1;
    m_logDataText = static_cast<wchar_t *>(malloc(characterCount * sizeof(wchar_t)));
    if (m_logDataText != 0)
        _wcscpy_s(m_logDataText, characterCount, source);
}

// UID:00028Q | by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md | Completion:88 | Confidence:92
Config *g_pConfig = 0;
