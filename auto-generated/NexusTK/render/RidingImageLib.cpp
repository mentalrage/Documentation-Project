// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000N6
// Source by-file doc: by-file/RidingImageLib.md
// UID:0000BZ | by-class/RidingImageLib.md | Completion:92 | Confidence:94
#include "RidingImageLib.h"

// UID:0002LA | by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md | Completion:89 | Confidence:91
#include "MonsterImageLibTables.h"

void RidingImageLib::LoadRidingDefinitions()
{
    DatFile reader;

    reader.Open(L"RIDINGS.DNA");
    reader.Read(&ridingDefinitionCount, sizeof(ridingDefinitionCount));

    ridingDefinitions = AllocateRidingDefinitionArray(ridingDefinitionCount);

    g_ridingDefinitionGroups.AllocateGroups(0x15);
    for (unsigned int groupIndex = 0; groupIndex < 0x15; ++groupIndex) {
        ImageAnimationGroup *group = g_ridingDefinitionGroups.GetGroup(groupIndex);

        group->AllocateFrames(1);
        group->frames[0].frameOffset = 0;
        group->frames[0].frameDuration = 30000;
        group->frames[0].blendAlpha = 0;
    }

    for (unsigned int ridingIndex = 0; ridingIndex < ridingDefinitionCount; ++ridingIndex) {
        RidingDefinition *definition = ridingDefinitions + ridingIndex;

        reader.Read(&definition->ridingId, sizeof(definition->ridingId));
        reader.Read(&definition->bucketCount, sizeof(definition->bucketCount));
        reader.Read(&definition->defaultBucketIndex, sizeof(definition->defaultBucketIndex));
        reader.Read(&definition->animationGroupId, sizeof(definition->animationGroupId));

        definition->buckets = AllocateRidingBucketArray(definition->bucketCount);
        for (unsigned int bucketIndex = 0; bucketIndex < definition->bucketCount; ++bucketIndex) {
            ImageAnimationGroup *bucket = definition->buckets + bucketIndex;

            reader.Read(&bucket->frameCount, sizeof(bucket->frameCount));
            bucket->AllocateFrames(bucket->frameCount);

            for (unsigned int entryIndex = 0; entryIndex < bucket->frameCount; ++entryIndex) {
                ImageAnimationFrame *entry = bucket->frames + entryIndex;

                reader.Read(&entry->frameOffset, sizeof(entry->frameOffset));
                reader.Read(&entry->frameDuration, sizeof(entry->frameDuration));
                reader.Read(&entry->auxFrameId, sizeof(entry->auxFrameId));
                reader.Read(&entry->blendAlpha, sizeof(entry->blendAlpha));
                reader.Read(&entry->paletteIndex, sizeof(entry->paletteIndex));
                reader.Read(&entry->effectIndex, sizeof(entry->effectIndex));
            }
        }
    }

    reader.Close();
}

// UID:0002Y0 | by-memory/0x004dc690-0x004dc722.RidingImageLibConstructor.md | Completion:88 | Confidence:91
RidingImageLib::RidingImageLib()
    : LObject(),
      ridingDefinitions(NULL),
      ridingDefinitionCount(0),
      ridingEpfPackage(NULL)
{
    g_pRidingImageLib = this;

    LoadRidingDefinitions();
    ridingEpfPackage = LoadImageFrameTable(L"RIDINGS.EPF", 0);
}

// UID:00017G | by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md | Completion:87 | Confidence:91
RidingImageLib::~RidingImageLib()
{
    MemoryManager *memory = GetMemoryMan();

    if (ridingEpfPackage != 0) {
        if (ridingEpfPackage->records != 0) {
            memory->Free(ridingEpfPackage->records);
        }

        memory->Free(ridingEpfPackage);
    }

    if (ridingDefinitions != 0) {
        DestroyRidingDefinitionArray(ridingDefinitions, ridingDefinitionCount);
        FreeRidingDefinitionArray(ridingDefinitions);
    }

    g_pRidingImageLib = 0;
}

// UID:0002Y1 | by-memory/0x004dc7e0-0x004dca14.RidingImageLibRenderRiding.md | Completion:92 | Confidence:94
void RidingImageLib::RenderRiding(
    GrafPort *target,
    const RectBounds *bounds,
    const ObjectStatusBlob *objectStatus,
    unsigned int animationGroup,
    unsigned int animationFrame)
{
    const unsigned int definitionIndex = static_cast<unsigned short>(
        objectStatus->m_appearanceId + 0x8000);
    if (definitionIndex >= ridingDefinitionCount)
        return;

    RidingDefinition *definition = ridingDefinitions + definitionIndex;
    RidingBucketEntry *frameEntry =
        definition->GetFrame(animationGroup, animationFrame);
    const int frameIndex =
        static_cast<int>(definition->ridingId) + frameEntry->frameOffset;
    const bool useCenteredProjection =
        definition->defaultBucketIndex != 0;

    definition->GetFrame(animationGroup, animationFrame);

    if (frameIndex < 0)
        return;

    EPFTileContext tileContext;
    g_pEPFLib->LookupLayoutEntry(
        L"RIDINGS.EPF",
        static_cast<short>(frameIndex),
        &tileContext);

    RectBounds sourceBounds = tileContext.bounds;
    RectBounds destinationBounds;
    destinationBounds.left = bounds->left;
    destinationBounds.top = bounds->top;
    destinationBounds.right =
        bounds->left + sourceBounds.right - sourceBounds.left;
    destinationBounds.bottom =
        bounds->top + sourceBounds.bottom - sourceBounds.top;

    if (animationGroup == 0)
        return;

    MapPane *mapPane = g_activeMapPane;

    if (sourceBounds.bottom < -4)
    {
        if (useCenteredProjection)
        {
            const int sourceHeight =
                sourceBounds.bottom - sourceBounds.top;
            OffsetRect(
                &destinationBounds,
                0,
                sourceHeight / 2 - sourceBounds.bottom);

            g_pfnBlitScaledRleTint(
                target,
                &tileContext,
                &sourceBounds,
                &destinationBounds,
                3,
                mapPane->m_dayNightTintAmount,
                0,
                1.5f,
                0.0f);
        }
        else
        {
            OffsetRect(&destinationBounds, 0, -sourceBounds.bottom);

            g_pfnBlitScaledRleTint(
                target,
                &tileContext,
                &sourceBounds,
                &destinationBounds,
                3,
                mapPane->m_dayNightTintAmount,
                0,
                mapPane->m_newHumanProjectionDivisor,
                mapPane->m_newHumanProjectionShear);
        }
        return;
    }

    if (useCenteredProjection)
        return;

    if (sourceBounds.bottom > 5)
    {
        RectBounds clippedSourceBounds = sourceBounds;
        clippedSourceBounds.bottom = 0;
        destinationBounds.bottom -= sourceBounds.bottom;

        if (mapPane != NULL)
        {
            g_pfnBlitScaledRleTint(
                target,
                &tileContext,
                &clippedSourceBounds,
                &destinationBounds,
                3,
                mapPane->m_dayNightTintAmount,
                0,
                mapPane->m_newHumanProjectionDivisor,
                mapPane->m_newHumanProjectionShear);
        }
        return;
    }

    g_pfnBlitScaledRleTint(
        target,
        &tileContext,
        &sourceBounds,
        &destinationBounds,
        3,
        mapPane->m_dayNightTintAmount,
        0,
        mapPane->m_newHumanProjectionDivisor,
        mapPane->m_newHumanProjectionShear);
}

// UID:0001VV | by-type/by-struct/RidingDefinition.md | Completion:90 | Confidence:92
typedef ImageAnimationGroup RidingBucket;
typedef ImageAnimationFrame RidingBucketEntry;

struct RidingDefinition
{
    unsigned int ridingId;
    unsigned char bucketCount;
    unsigned char defaultBucketIndex;
    unsigned short animationGroupId;
    RidingBucket *buckets;

    RidingBucketEntry *GetFrame(
        unsigned int groupIndex,
        unsigned int frameIndex);
};

// UID:0001VW | by-type/by-struct/RidingImageLibLayout.md | Completion:86 | Confidence:91
// RidingImageLib object layout is emitted by the [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md) class shell:
// +0x04 ridingDefinitions, +0x08 ridingDefinitionCount, +0x0c ridingEpfPackage.

// UID:0001YM | by-type/by-vtable/RidingImageLibVtable.md | Completion:86 | Confidence:91
// RidingImageLib vtable data is compiler-generated from the class declaration
// and virtual destructor. Do not emit a hand-authored source vtable.

// UID:0000TJ | by-global/RidingDefinitionGlobalTable.md | Completion:90 | Confidence:91
ImageAnimationTable g_ridingDefinitionGroups;

// UID:0000S4 | by-global/g_pRidingImageLib.md | Completion:90 | Confidence:91
RidingImageLib *g_pRidingImageLib = NULL;
