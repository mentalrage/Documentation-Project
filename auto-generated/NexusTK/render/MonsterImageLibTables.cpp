// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LK
// Source by-file doc: by-file/MonsterImageLibTables.md
// UID:0001CM | by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md | Completion:94 | Confidence:94
#include "MonsterImageLibTables.h"

ImageAnimationTable::ImageAnimationTable()
{
    baseValue = 0;
    groupCount = 0;
    flags = 0;
    tableId = 0;
    groups = NULL;
}

ImageAnimationTable::~ImageAnimationTable()
{
    delete[] groups;
    groupCount = 0;
    groups = NULL;
}

void ImageAnimationTable::AllocateGroups(unsigned int count)
{
    groups = new ImageAnimationGroup[count];
    groupCount = (unsigned char)count;
}

ImageAnimationGroup *ImageAnimationTable::GetGroup(unsigned int groupIndex)
{
    ImageAnimationGroup *group = groups;
    if (groupIndex < groupCount)
        group += groupIndex;
    return group;
}

ImageAnimationFrame *ImageAnimationTable::GetFrame(unsigned int groupIndex, unsigned int frameIndex)
{
    ImageAnimationGroup *group = groups;
    if (groupIndex < groupCount)
        group += groupIndex;

    if (frameIndex < group->frameCount)
        return group->frames + frameIndex;

    return &g_defaultImageAnimationFrame;
}

ImageAnimationGroup::ImageAnimationGroup()
{
    frames = NULL;
    frameCount = 0;
}

ImageAnimationGroup::~ImageAnimationGroup()
{
    delete[] frames;
    frames = NULL;
    frameCount = 0;
}

void ImageAnimationGroup::AllocateFrames(unsigned int count)
{
    frames = new ImageAnimationFrame[count];
    frameCount = (unsigned short)(unsigned char)count;
}

ImageAnimationFrame *ImageAnimationGroup::GetFrame(unsigned int frameIndex)
{
    if (frameIndex < frameCount)
        return frames + frameIndex;

    return &g_defaultImageAnimationFrame;
}

ImageAnimationFrame::ImageAnimationFrame()
{
    frameOffset = 0;
    frameDuration = 0;
    blendAlpha = 0xff;
    auxFrameId = -1;
    paletteIndex = 0;
    effectIndex = 0;
}

// UID:00027U | by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md | Completion:94 | Confidence:94
ImageAnimationFrame g_defaultImageAnimationFrame;
