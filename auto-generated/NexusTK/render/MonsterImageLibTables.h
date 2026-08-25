// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LK
// Source by-file doc: by-file/MonsterImageLibTables.md
// UID:0001CM | by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md | Completion:94 | Confidence:94
#ifndef NEXUSTK_RENDER_MONSTERIMAGELIBTABLES_H
#define NEXUSTK_RENDER_MONSTERIMAGELIBTABLES_H

struct ImageAnimationFrame
{
    short frameOffset;
    short frameDuration;
    unsigned char blendAlpha;
    unsigned char reserved;
    short auxFrameId;
    unsigned char paletteIndex;
    unsigned char effectIndex;

    ImageAnimationFrame();
};

struct ImageAnimationGroup
{
    ImageAnimationFrame *frames;
    unsigned short frameCount;

    ImageAnimationGroup();
    ~ImageAnimationGroup();

    void AllocateFrames(unsigned int count);
    ImageAnimationFrame *GetFrame(unsigned int frameIndex);
};

struct ImageAnimationTable
{
    int baseValue;
    unsigned char groupCount;
    unsigned char flags;
    unsigned short tableId;
    ImageAnimationGroup *groups;

    ImageAnimationTable();
    ~ImageAnimationTable();

    void AllocateGroups(unsigned int count);
    ImageAnimationGroup *GetGroup(unsigned int groupIndex);
    ImageAnimationFrame *GetFrame(
        unsigned int groupIndex,
        unsigned int frameIndex);
};

extern ImageAnimationFrame g_defaultImageAnimationFrame;

#endif
