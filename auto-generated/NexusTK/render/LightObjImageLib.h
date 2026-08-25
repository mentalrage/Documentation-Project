// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KP
// Source by-file doc: by-file/LightObjImageLib.md
// UID:000076 | by-class/LightObjImageLib.md | Completion:92 | Confidence:94
#ifndef NEXUSTK_GFX_LIGHTOBJIMAGELIB_H
#define NEXUSTK_GFX_LIGHTOBJIMAGELIB_H

#include "../util/LObject.h"
#include "../util/ProtectedArray.h"
#include "../util/Singleton.h"

class IntAlphaSurface;
struct RectBounds;

// UID:0001UW | by-type/by-struct/LightInfo.md | Completion:90 | Confidence:92
struct LightInfo
{
    int tableId;
    int innerRadius;
    int radiusX;
    int radiusY;
    float brightness;
    float blendScale;
    IntAlphaSurface *generatedFrame;
};

// UID:0001UX | by-type/by-struct/LightObjImageLibLayout.md | Completion:92 | Confidence:94
class LightObjImageLib : public LObject, public Singleton<LightObjImageLib>
{
public:
    LightObjImageLib();
    virtual ~LightObjImageLib();

    void GetLightBounds(int lightImageIndex, RectBounds *outBounds);
    virtual void DrawLightMode1(
        IntAlphaSurface *targetSurface,
        int centerX,
        int centerY,
        int lightImageIndex);
    virtual void DrawLightMode2(
        IntAlphaSurface *targetSurface,
        int centerX,
        int centerY,
        int lightImageIndex);

    float GetBrightness(int lightImageIndex)
    {
        return m_lightInfos.GetAtOrDefault(lightImageIndex)->brightness;
    }

private:
    ProtectedArray<LightInfo> m_lightInfos;
};

extern LightObjImageLib *g_pLightObjImageLib;

#endif
