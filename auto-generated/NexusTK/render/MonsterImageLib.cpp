// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LJ
// Source by-file doc: by-file/MonsterImageLib.md
// UID:00008N | by-class/MonsterImageLib.md | Completion:91 | Confidence:92
#include "MonsterImageLib.h"

// UID:0000RR | by-global/g_pMonsterImageLib.md | Completion:91 | Confidence:92
MonsterImageLib *g_pMonsterImageLib = NULL;

// UID:0002JN | by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md | Completion:90 | Confidence:91
#include "MonsterImageLibTables.h"

void MonsterImageLib::LoadMonsterTables()
{
    static const unsigned int kDefaultMonsterGroupCount = 21;
    static const unsigned short kDefaultFrameDuration = 30000;

    DATFile tableFile;

    if (g_usesCompactMonsterTable)
        tableFile.Open(L"MONSTER.DNA");
    else
        tableFile.Open(L"MONSTER.DND");

    unsigned int monsterCount = 0;
    tableFile.Read(&monsterCount, sizeof(monsterCount));

    if (monsterCount != 0)
        m_monsters = new MonsterImageEntry[monsterCount];
    else
        m_monsters = 0;

    m_monsterCount = monsterCount;

    g_defaultMonsterAnimationTable.AllocateGroups(kDefaultMonsterGroupCount);
    for (unsigned int groupIndex = 0; groupIndex < kDefaultMonsterGroupCount; ++groupIndex)
    {
        ImageAnimationGroup& group = g_defaultMonsterAnimationTable.groups[groupIndex];

        group.AllocateFrames(1);
        group.frames[0].frameOffset = 0;
        group.frames[0].frameDuration = kDefaultFrameDuration;
        group.frames[0].blendAlpha = 0;
    }

    for (unsigned int monsterIndex = 0; monsterIndex < monsterCount; ++monsterIndex)
    {
        MonsterImageEntry& monster = m_monsters[monsterIndex];

        tableFile.Read(&monster.baseFrameIndex, sizeof(monster.baseFrameIndex));
        tableFile.Read(&monster.animationGroupCount, sizeof(monster.animationGroupCount));
        tableFile.Read(&monster.projectionFlag, sizeof(monster.projectionFlag));
        tableFile.Read(&monster.paletteTableId, sizeof(monster.paletteTableId));

        monster.AllocateGroups(monster.animationGroupCount);

        for (unsigned int groupIndex = 0; groupIndex < monster.animationGroupCount; ++groupIndex)
        {
            ImageAnimationGroup& group = monster.groups[groupIndex];

            tableFile.Read(&group.frameCount, sizeof(group.frameCount));
            group.AllocateFrames(group.frameCount);

            for (unsigned int frameIndex = 0; frameIndex < group.frameCount; ++frameIndex)
            {
                ImageAnimationFrame& frame = group.frames[frameIndex];

                tableFile.Read(&frame.frameOffset, sizeof(frame.frameOffset));
                tableFile.Read(&frame.frameDuration, sizeof(frame.frameDuration));
                tableFile.Read(&frame.auxFrameId, sizeof(frame.auxFrameId));
                tableFile.Read(&frame.blendAlpha, sizeof(frame.blendAlpha));
                tableFile.Read(&frame.paletteIndex, sizeof(frame.paletteIndex));
                tableFile.Read(&frame.effectIndex, sizeof(frame.effectIndex));
            }
        }
    }

    tableFile.Close();
}

// UID:00017D | by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md | Completion:90 | Confidence:91
MonsterImageLib::~MonsterImageLib()
{
    ClearLoadedData();
    delete[] m_monsters;
}

// UID:00017E | by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md | Completion:88 | Confidence:91
// MonsterImageLib::GetArchiveBoundsBucket is intentionally not emitted as a
// standalone body yet. [UID:00017E] documents the exact lazy DATA/MON%d.DAT
// bounds-cache behavior, but source-quality C++ still requires final DAT
// archive/vector ownership APIs.

// UID:0003M1 | by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md | Completion:86 | Confidence:91
// This scalar deleting destructor is compiler-generated from the
// MonsterImageLib virtual destructor and vtable. The authored destructor source
// is emitted by [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md).

// UID:0001VA | by-type/by-struct/MonsterArchiveBoundsBucket.md | Completion:88 | Confidence:91
struct MonsterArchiveBoundsBucket
{
    unsigned short entryCount;
    unsigned short maxExtent02;
    unsigned short maxExtent04;
    unsigned short header06;
    MonsterArchiveBoundsEntry *entries;
};

// UID:0001VB | by-type/by-struct/MonsterArchiveBoundsEntry.md | Completion:87 | Confidence:91
struct MonsterArchiveBoundsEntry
{
    RectBounds rect;
    const unsigned char *payloadStart;
    const unsigned char *payloadEnd;
};

// UID:0001VC | by-type/by-struct/MonsterImageEntry.md | Completion:88 | Confidence:89
struct MonsterImageEntry
{
    int baseFrameIndex;
    unsigned char animationGroupCount;
    unsigned char projectionFlag;
    unsigned short paletteTableId;
    ImageAnimationGroup *groups;

    void AllocateGroups(unsigned int count);
    ImageAnimationGroup *GetGroup(unsigned int groupIndex);
    ImageAnimationFrame *GetFrame(unsigned int groupIndex, unsigned int frameIndex);
};

// UID:0001VD | by-type/by-struct/MonsterImageLibLayout.md | Completion:87 | Confidence:90
// MonsterImageLibLayout is an evidence page for the concrete MonsterImageLib
// object layout. Do not emit a duplicate ABI struct; source declarations belong
// on [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) and exact child pages.

// UID:0001Y7 | by-type/by-vtable/MonsterImageLibVtable.md | Completion:87 | Confidence:92
// MonsterImageLib vtable bytes are compiler-generated from the class
// declaration and virtual destructor; do not hand-emit a source vtable object.
// UID:0002MM | by-memory/0x0061b6e0-0x0061b6f0.MonsterImageLibVtableData.md | Completion:90 | Confidence:92
// Emitted vtable data for 0x0061b6e0-0x0061b6f0 is covered by
// [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md) and the MonsterImageLib class declaration. This exact .rdata
// range is compiler-generated output, not a hand-authored source table.

// UID:0002VF | by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md | Completion:88 | Confidence:92
// VectorGrowArchiveIndex is the compiler-lowered grow/insert path for
// MonsterImageLib::LoadMonsterArchives' 4-byte archive-offset vector. Final
// source should express the operation in LoadMonsterArchives, not as a
// standalone helper body.

// UID:000181 | by-memory/0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper.md | Completion:88 | Confidence:93
static void ClearMonsterImageLibSingleton()
{
    g_pMonsterImageLib = NULL;
}

// UID:0004DM | by-memory/0x004e6df0-0x004e6e49.VectorStorageReplaceForArchiveIndex.md | Completion:87 | Confidence:91
// This storage replacement helper is the one-caller dependency of
// MonsterImageLib::LoadMonsterArchives' archive-index vector grow path.
// Final source should be expressed through that MonsterImageLib vector source
// route, not as a standalone decompiler-shaped storage helper.

// UID:00029K | by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md | Completion:88 | Confidence:92
static ImageAnimationTable g_defaultMonsterAnimationTable;
