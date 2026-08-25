// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KO
// Source by-file doc: by-file/LightingObjectPane.md
// UID:000075 | by-class/LightingObjectPane.md | Completion:94 | Confidence:95
#ifndef NEXUSTK_MAP_LIGHTINGOBJECTPANE_H
#define NEXUSTK_MAP_LIGHTINGOBJECTPANE_H

#include "ObjectPane.h"

class MapPane;
struct MapPoint;
struct RectBounds;

class LightingObjectPane : public ObjectPane
{
public:
    LightingObjectPane(
        ObjectPane *anchorSource,
        int mapY,
        int mapX,
        int localOffsetX,
        int localOffsetY,
        int lightImageIndex);
    virtual ~LightingObjectPane();

    float GetBrightness() const;
    MapPoint *GetAnchorScreenPoint(MapPoint *outPoint) const;
    RectBounds *GetLightBounds(RectBounds *outBounds) const;
    void QueueLightBounds() const;
    void SetLightImageIndex(int lightImageIndex);
    void ApplyLightAtAnchor(MapPane *mapPane, int centerX, int centerY) const;
    void ApplyLightMode2AtAnchor(MapPane *mapPane, int centerX, int centerY) const;

private:
    int m_lightImageIndex;
    int m_localOffsetY;
    int m_localOffsetX;
    ObjectPane *m_anchorSource;
};

#endif
