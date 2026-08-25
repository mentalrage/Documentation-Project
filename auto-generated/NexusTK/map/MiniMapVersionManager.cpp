// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LF
// Source by-file doc: by-file/MiniMapVersionManager.md
// UID:0001V8 | by-type/by-struct/MiniMapVersionNode.md | Completion:90 | Confidence:93
#include "MiniMapVersionManager.h"

struct MiniMapVersionNode
{
    MiniMapVersionNode *next;
    MiniMapVersionNode *prev;
    int mapId;
    wchar_t *expectedVersionString;
};

// UID:00008H | by-class/MiniMapVersionManager.md | Completion:91 | Confidence:93



// UID:0004DB | by-memory/0x00456700-0x00456791.MiniMapVersionManagerClearHashList.md | Completion:89 | Confidence:91
void MiniMapVersionManager::ClearHashList()
{
    VersionIndex::iterator it = m_versionIndex.begin();
    while (it != m_versionIndex.end())
    {
        delete [] it->second;
        ++it;
    }

    m_versionIndex.clear();
}


// UID:0002JM | by-memory/0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString.md | Completion:89 | Confidence:93
const wchar_t* MiniMapVersionManager::GetVersionString() const
{
    return m_currentVersion;
}

// UID:0000XQ | by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md | Completion:88 | Confidence:92
const wchar_t *MiniMapVersionManager::GetExpectedVersionForMapId(int mapId) const
{
    VersionIndex::const_iterator it = m_versionIndex.find(mapId);
    if (it == m_versionIndex.end())
        return NULL;

    return it->second;
}



// UID:0000RP | by-global/g_pMiniMapVersionManager.md | Completion:92 | Confidence:94
MiniMapVersionManager *g_pMiniMapVersionManager = 0;

// UID:0001OZ | by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md | Completion:92 | Confidence:94
// Exact storage for g_pMiniMapVersionManager at 0x0067a7dc.
// The source definition is emitted by [UID:0000RP][g_pMiniMapVersionManager](by-global/g_pMiniMapVersionManager.md);
// do not duplicate the pointer definition from this storage child.

// UID:0004D8 | by-memory\0x004563c0-0x0045647d.MiniMapVersionManagerConstructor.md | Completion:88 | Confidence:91 | Empty Emitter Marker

// UID:0004D9 | by-memory\0x00456480-0x00456532.MiniMapVersionManagerDestructor.md | Completion:88 | Confidence:91 | Empty Emitter Marker

// UID:0004DA | by-memory\0x00456540-0x004566fe.MiniMapVersionManagerLoadHashFile.md | Completion:87 | Confidence:91 | Empty Emitter Marker

// UID:0002JL | by-memory\0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList.md | Completion:87 | Confidence:91 | Empty Emitter Marker

// UID:0004DE | by-memory\0x004573c0-0x004573cb.MiniMapVersionManagerClearSingletonHelper.md | Completion:88 | Confidence:93 | Empty Emitter Marker

// UID:0003FQ | by-memory\0x006108d4-0x00610980.MiniMapVersionManagerReadOnlyData.md | Completion:86 | Confidence:91 | Empty Emitter Marker

// UID:0000XP | by-memory\0x004563c0-0x00457547.MiniMapVersionManager.md | Completion:88 | Confidence:90 | Empty Emitter Marker
