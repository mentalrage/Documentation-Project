// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000M6
// Source by-file doc: by-file/ObjectStatusBlob.md
// UID:00009S | by-class/ObjectStatusBlob.md | Completion:94 | Confidence:94
#ifndef NEXUSTK_MAP_OBJECTSTATUSBLOB_H
#define NEXUSTK_MAP_OBJECTSTATUSBLOB_H

#include "../render/NewHumanImageLib.h"

class ObjectStatusBlob : public HumanImageRenderParams
{
public:
    enum StatusKind
    {
        HumanObject = 0,
        FullLivingObject = HumanObject,
        MonsterObject = 1,
        CompactLivingObject = MonsterObject,
        ItemObject = 2
    };

    int ParseTaggedStatus(const unsigned char *packet);
    int ParseFullStatus(const unsigned char *packet);
    int ParsePartialStatus(const unsigned char *packet);

    unsigned char m_faceShape;
    unsigned char m_trailingPadding[3];
};

typedef char ObjectStatusBlobSizeMustBe68[
    sizeof(ObjectStatusBlob) == 0x44 ? 1 : -1];

#endif
