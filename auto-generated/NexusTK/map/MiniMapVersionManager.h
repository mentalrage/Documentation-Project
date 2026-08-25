// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LF
// Source by-file doc: by-file/MiniMapVersionManager.md
// UID:00008H | by-class/MiniMapVersionManager.md | Completion:91 | Confidence:93
#ifndef NEXUSTK_MAP_MINIMAPVERSIONMANAGER_H
#define NEXUSTK_MAP_MINIMAPVERSIONMANAGER_H

#include <hash_map>

#include "../util/Singleton.h"

class MiniMapVersionManager : public Singleton<MiniMapVersionManager>
{
public:
    MiniMapVersionManager();
    virtual ~MiniMapVersionManager();

    void LoadHashFile();
    void ClearHashList();
    void UpdateHashList(const wchar_t *versionString,
                        wchar_t *hashListText,
                        bool saveCache);
    const wchar_t *GetVersionString() const;
    const wchar_t *GetExpectedVersionForMapId(int mapId) const;

private:
    typedef stdext::hash_map<int, wchar_t *> VersionIndex;

    wchar_t m_currentVersion[33];
    VersionIndex m_versionIndex;
};

extern MiniMapVersionManager *g_pMiniMapVersionManager;

typedef char MiniMapVersionManagerSizeMustBe0x68[
    sizeof(MiniMapVersionManager) == 0x68 ? 1 : -1];

#endif
