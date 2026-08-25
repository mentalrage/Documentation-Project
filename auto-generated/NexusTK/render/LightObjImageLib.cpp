// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KP
// Source by-file doc: by-file/LightObjImageLib.md
// UID:0000RD | by-global/g_pLightObjImageLib.md | Completion:92 | Confidence:94
LightObjImageLib *g_pLightObjImageLib = 0;

// UID:000076 | by-class/LightObjImageLib.md | Completion:92 | Confidence:94
#include "LightObjImageLib.h"



// UID:0002IU | by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md | Completion:92 | Confidence:94
LightObjImageLib::LightObjImageLib()
    : Singleton<LightObjImageLib>()
{
    m_lightInfos.m_count = 0;
    m_lightInfos.m_entries = 0;
    m_lightInfos.m_defaultCapacity = 10;

    m_lightInfos.m_defaultEntry.tableId = -1;
    m_lightInfos.m_defaultEntry.innerRadius = -1;
    m_lightInfos.m_defaultEntry.radiusX = -1;
    m_lightInfos.m_defaultEntry.radiusY = -1;
    m_lightInfos.m_defaultEntry.brightness = 0.0f;
    m_lightInfos.m_defaultEntry.blendScale = 0.0f;
    m_lightInfos.m_defaultEntry.generatedFrame = 0;

    DATFile lightTable;
    lightTable.Open(L"LIGHT.TBL");

    int lightCount = 0;
    ReadEncodedTableInt(&lightTable, &lightCount);

    if (lightCount > 0 && m_lightInfos.m_count != lightCount) {
        LightInfo *newEntries = static_cast<LightInfo *>(operator new(sizeof(LightInfo) * lightCount));
        if (m_lightInfos.m_entries != 0) {
            int copyCount = lightCount;
            if (m_lightInfos.m_count < copyCount)
                copyCount = m_lightInfos.m_count;
            memmove(newEntries, m_lightInfos.m_entries, sizeof(LightInfo) * copyCount);
            free(m_lightInfos.m_entries);
        }
        m_lightInfos.m_count = lightCount;
        m_lightInfos.m_entries = newEntries;
    }

    for (int index = 0; index < lightCount; ++index) {
        LightInfo lightInfo;
        ReadEncodedTableInt(&lightTable, &lightInfo.tableId);
        ReadEncodedTableInt(&lightTable, &lightInfo.innerRadius);
        ReadEncodedTableInt(&lightTable, &lightInfo.radiusX);
        ReadEncodedTableInt(&lightTable, &lightInfo.radiusY);
        ReadEncodedTableFloat(&lightTable, &lightInfo.brightness);
        ReadEncodedTableFloat(&lightTable, &lightInfo.blendScale);
        lightInfo.generatedFrame = 0;

        if (lightInfo.radiusX > 0 && lightInfo.radiusY > 0) {
            const int width = lightInfo.radiusX * 2 + 1;
            const int height = lightInfo.radiusY * 2 + 1;
            lightInfo.generatedFrame = new IntAlphaSurface(width, height);
            if (lightInfo.generatedFrame != 0) {
                RectBounds frameRect;
                InitRectBounds(&frameRect, 0, 0, width, height);
                lightInfo.generatedFrame->ApplyRectAlpha(&frameRect, 0, 0);
                int center[2];
                lightInfo.generatedFrame->GetCenterPoint(center);
                const int innerAlpha = static_cast<int>(lightInfo.brightness * 32.0f + 0.5f);
                lightInfo.generatedFrame->FillEllipticGradient(center[1], center[0],
                    lightInfo.innerRadius, lightInfo.radiusX, lightInfo.radiusY,
                    static_cast<unsigned char>(innerAlpha), 0, lightInfo.blendScale, 0);
            }
        }

        LightInfo *slot = &m_lightInfos.m_defaultEntry;
        if (index >= 0 && index < m_lightInfos.m_count)
            slot = &m_lightInfos.m_entries[index];
        *slot = lightInfo;
    }
}

// UID:00017Q | by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md | Completion:92 | Confidence:94
LightObjImageLib::~LightObjImageLib()
{
    for (int index = 0; index < m_lightInfos.m_count; ++index) {
        IntAlphaSurface *frame = m_lightInfos.m_entries[index].generatedFrame;
        if (frame != 0)
            delete frame;
    }
}

// UID:0002IV | by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md | Completion:92 | Confidence:94
void LightObjImageLib::GetLightBounds(int lightIndex, RectBounds *outBounds)
{
    const LightInfo *lightInfo = &m_lightInfos.m_defaultEntry;
    if (lightIndex >= 0 && lightIndex < m_lightInfos.m_count)
        lightInfo = &m_lightInfos.m_entries[lightIndex];
    if (lightInfo->generatedFrame != 0) {
        InitRectBounds(outBounds, -lightInfo->radiusX, -lightInfo->radiusY,
            lightInfo->radiusX + 1, lightInfo->radiusY + 1);
        return;
    }
    InitRectBounds(outBounds, 0, 0, 0, 0);
}

// UID:0002IW | by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md | Completion:92 | Confidence:94
void LightObjImageLib::DrawLightMode1(IntAlphaSurface *targetSurface, int centerX, int centerY, int lightIndex)
{
    const LightInfo *lightInfo = &m_lightInfos.m_defaultEntry;
    if (lightIndex >= 0 && lightIndex < m_lightInfos.m_count)
        lightInfo = &m_lightInfos.m_entries[lightIndex];
    IntAlphaSurface *sourceFrame = lightInfo->generatedFrame;
    if (sourceFrame == 0)
        return;
    const int width = sourceFrame->width;
    const int height = sourceFrame->height;
    RectBounds sourceRect;
    InitRectBounds(&sourceRect, 0, 0, width, height);
    RectBounds destinationRect;
    InitRectBounds(&destinationRect, centerX - width / 2, centerY - height / 2,
        centerX - width / 2 + width, centerY - height / 2 + height);
    targetSurface->DrawFrameWithBlendMode(&destinationRect, sourceFrame, &sourceRect, 1);
}

// UID:0002IX | by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md | Completion:92 | Confidence:94
void LightObjImageLib::DrawLightMode2(IntAlphaSurface *targetSurface, int centerX, int centerY, int lightIndex)
{
    const LightInfo *lightInfo = &m_lightInfos.m_defaultEntry;
    if (lightIndex >= 0 && lightIndex < m_lightInfos.m_count)
        lightInfo = &m_lightInfos.m_entries[lightIndex];
    IntAlphaSurface *sourceFrame = lightInfo->generatedFrame;
    if (sourceFrame == 0)
        return;
    const int width = sourceFrame->width;
    const int height = sourceFrame->height;
    RectBounds sourceRect;
    InitRectBounds(&sourceRect, 0, 0, width, height);
    RectBounds destinationRect;
    InitRectBounds(&destinationRect, centerX - width / 2, centerY - height / 2,
        centerX - width / 2 + width, centerY - height / 2 + height);
    targetSurface->DrawFrameWithBlendMode(&destinationRect, sourceFrame, &sourceRect, 2);
}

// UID:0001UW | by-type\by-struct\LightInfo.md | Completion:90 | Confidence:92 | Empty Emitter Marker

// UID:0001UX | by-type\by-struct\LightObjImageLibLayout.md | Completion:92 | Confidence:94 | Empty Emitter Marker
