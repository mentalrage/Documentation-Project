// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KH
// Source by-file doc: by-file/ItemObjImageLib.md
// UID:00006W | by-class/ItemObjImageLib.md | Completion:93 | Confidence:94
#ifndef NEXUSTK_RENDER_ITEMOBJIMAGELIB_H
#define NEXUSTK_RENDER_ITEMOBJIMAGELIB_H

#include "../ui/core/RectBounds.h"
#include "../util/LObject.h"
#include "../util/Singleton.h"

class IntAlphaSurface;
class GrafPort;
class MapPane;
struct ItemInfo;
template <class T> class ProtectedArray;

// UID:0001UU | by-type/by-struct/ItemObjImageLibLayout.md | Completion:92 | Confidence:94
class ItemObjImageLib : public LObject, public Singleton<ItemObjImageLib>
{
public:
    ItemObjImageLib();
    virtual ~ItemObjImageLib();

    int DrawItemImage(void *drawOwner, const RectBounds *dstRect, short itemId, unsigned char paletteFlags, IntAlphaSurface *overlayMask, float overlayStrength);
    void DrawItemImageIn43x43Slot(
        GrafPort *drawPort,
        RectBounds *destinationBounds,
        short itemId,
        unsigned char paletteFlags,
        IntAlphaSurface *overlayMask,
        float overlayStrength);
    int DrawItemImageUnscaled(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags);
    int DrawItemImageScaled(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags);
    void GetItemGlyphBounds(short itemId, RectBounds *outBounds);

private:
    friend class MapPane;

    void RefreshItemFrameAvailability();

    ProtectedArray<ItemInfo> m_itemInfos;
};

extern ItemObjImageLib *g_pItemObjImageLib;

#endif
