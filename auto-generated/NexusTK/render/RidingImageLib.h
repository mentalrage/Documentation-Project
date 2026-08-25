// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000N6
// Source by-file doc: by-file/RidingImageLib.md
// UID:0000BZ | by-class/RidingImageLib.md | Completion:92 | Confidence:94
#ifndef NEXUSTK_RENDER_RIDINGIMAGELIB_H
#define NEXUSTK_RENDER_RIDINGIMAGELIB_H

#include "../util/LObject.h"

struct ArchiveMetadataTable;
struct ImageAnimationTable;
struct ImageAnimationGroup;
struct ImageAnimationFrame;
struct RidingDefinition;
struct ObjectStatusBlob;
struct RectBounds;
class GrafPort;
class NewHumanImageLib;

class RidingImageLib : public LObject
{
public:
    RidingImageLib();
    virtual ~RidingImageLib();

    void LoadRidingDefinitions();
    void RenderRiding(
        GrafPort *target,
        const RectBounds *bounds,
        const ObjectStatusBlob *objectStatus,
        unsigned int animationGroup,
        unsigned int animationFrame);
    const RidingDefinition *GetDefinitionOrDefault(
        unsigned int ridingDefinitionIndex) const;

private:
    friend class NewHumanImageLib;
    RidingDefinition *ridingDefinitions;
    unsigned int ridingDefinitionCount;
    ArchiveMetadataTable *ridingEpfPackage;
};

extern RidingImageLib *g_pRidingImageLib;
extern ImageAnimationTable g_ridingDefinitionGroups;

#endif
