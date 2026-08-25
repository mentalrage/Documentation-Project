// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000O6
// Source by-file doc: by-file/StaticObjectPane.md
// UID:0000E1 | by-class/StaticObjectPane.md | Completion:90 | Confidence:92
#ifndef NEXUSTK_MAP_STATICOBJECTPANE_H
#define NEXUSTK_MAP_STATICOBJECTPANE_H

#include "ObjectPane.h"

class PaneEvent;
struct Rect;
struct StaticObjectDrawRequest;

class StaticObjectPane : public ObjectPane
{
public:
    StaticObjectPane(int tileX, int tileY, unsigned short staticObjectId);
    virtual ~StaticObjectPane() {}

    bool HitTestStaticObjectPixel(int localX, int localY) const;
    virtual Rect *CopyStaticObjectBounds(Rect *scratch, Rect *out) const;
    virtual bool RenderStaticObjectForTarget(
        int renderMode,
        StaticObjectDrawRequest *request);
    virtual bool HandleStaticObjectEvent(const PaneEvent *event);

    unsigned short GetStaticObjectId() const
    {
        return m_staticObjectId;
    }

private:
    void SendInteractionPacket();
    unsigned short m_staticObjectId;
};

typedef char StaticObjectPaneSizeMustBe0x12c[
    sizeof(StaticObjectPane) == 0x12c ? 1 : -1];

#endif
