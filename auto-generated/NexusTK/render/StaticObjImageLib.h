// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000O7
// Source by-file doc: by-file/StaticObjImageLib.md
// UID:0000E2 | by-class/StaticObjImageLib.md | Completion:92 | Confidence:96
#ifndef NEXUSTK_RENDER_STATICOBJIMAGELIB_H
#define NEXUSTK_RENDER_STATICOBJIMAGELIB_H

#include "../util/LObject.h"
#include "../util/Singleton.h"

struct ArchiveMetadataTable;
struct Rect;
struct GrafPort;
struct StaticObjectDrawRequest;

struct TileClassEntry
{
    unsigned short tileFrameId;
    unsigned char allowPaletteFilter;
    unsigned char reserved;
};

#pragma pack(push, 2)
struct StaticObjEntry
{
    int lightImageIndex;
    unsigned char lightHeightClass;
    unsigned char layerCount;
    unsigned short reserved;
    StaticObjEntry *cacheChain;
    unsigned short tileIds[1];
};
#pragma pack(pop)

class StaticObjImageLib : public LObject,
                          public Singleton<StaticObjImageLib>
{
public:
    StaticObjImageLib();
    virtual ~StaticObjImageLib();

    char RenderStaticObject(GrafPort *target,
                            StaticObjectDrawRequest *request,
                            unsigned short staticObjectId,
                            void *overlayBuffer,
                            float overlayAlpha,
                            bool enableBlendClip);
    void GetStaticObjectBounds(unsigned short staticObjectId, Rect *outBounds) const;
    bool HitTestStaticObjectPixel(unsigned short staticObjectId,
                                  int localX,
                                  int localY) const;
    StaticObjEntry *GetStaticObjectEntry(unsigned short staticObjectId) const;

private:
    ArchiveMetadataTable *tileCatalog;
    TileClassEntry *tileClasses;
    StaticObjEntry **staticObjEntries;
    int staticObjCount;
};

extern StaticObjImageLib *g_pStaticObjImageLib;

#endif
