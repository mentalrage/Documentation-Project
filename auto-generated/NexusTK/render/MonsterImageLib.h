// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LJ
// Source by-file doc: by-file/MonsterImageLib.md
// UID:00008N | by-class/MonsterImageLib.md | Completion:91 | Confidence:92
#ifndef NEXUSTK_RENDER_MONSTERIMAGELIB_H
#define NEXUSTK_RENDER_MONSTERIMAGELIB_H

#include "../util/LObject.h"
#include <hash_map>
#include <vector>

class DATFile;
struct EPFTileContext;
class GrafPort;
class ObjectStatusBlob;
struct FrameDrawRecord;
struct MonsterArchiveBoundsBucket;
struct MonsterImageEntry;
struct RectBounds;

class MonsterImageLib : public LObject
{
public:
    MonsterImageLib();
    virtual ~MonsterImageLib();

    void LoadMonsterTables();
    void LoadMonsterArchives();
    void ClearLoadedData();
    MonsterImageEntry *GetEntryByIndex(unsigned int index);
    void RenderMonster(
        GrafPort *target, const RectBounds *bounds,
        const ObjectStatusBlob *status, unsigned int animationGroup,
        unsigned int frameIndex);
    MonsterArchiveBoundsBucket *GetArchiveBoundsBucket(
        unsigned int archiveIndex);
    void ResolveMonsterArchiveBounds(
        unsigned int frameIndex, EPFTileContext *context);
    int ComputeRenderBounds(
        const ObjectStatusBlob *status, unsigned int direction,
        unsigned int frameIndex, RectBounds *bounds,
        RectBounds *secondaryBounds);
    void RenderMonsterImage(
        GrafPort *port, const RectBounds *destinationBounds,
        const ObjectStatusBlob *status, int direction,
        unsigned int frameIndex, int renderMode,
        unsigned int effectState, FrameDrawRecord *frameRecord,
        float overlayStrength);

private:
    MonsterImageEntry *m_monsters;
    unsigned int m_monsterCount;
    unsigned int m_archiveState;
    std::vector<unsigned int> m_archiveOffsets;
    stdext::hash_map<int, DATFile *> m_openArchiveIndex;
    stdext::hash_map<int, MonsterArchiveBoundsBucket *> m_boundsBucketIndex;
};

// UID:0000RR | by-global/g_pMonsterImageLib.md | Completion:91 | Confidence:92
extern MonsterImageLib *g_pMonsterImageLib;

typedef char MonsterImageLibSizeMustBe92[
    sizeof(MonsterImageLib) == 0x5c ? 1 : -1];

#endif
