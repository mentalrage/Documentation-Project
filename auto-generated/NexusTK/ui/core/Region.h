// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000N3
// Source by-file doc: by-file/Region.md
// UID:0000BV | by-class/Region.md | Completion:94 | Confidence:94
#ifndef NEXUSTK_UI_CORE_REGION_H
#define NEXUSTK_UI_CORE_REGION_H

#include "../../util/LObject.h"
#include "RectBounds.h"

class Region : public LObject
{
public:
    Region();
    virtual ~Region();

    bool IsEmpty() const;
    void SetEmpty();
    void SetRect(const RectBounds *bounds);
    void CopyRectFrom(const Region &region);
    bool IntersectWith(const Region &region);
    bool IntersectWithRect(const RectBounds *bounds);
    void UnionWithRect(const RectBounds *bounds);
    void UnionWith(const Region &region);
    void SubtractRect(const RectBounds *bounds);
    void SubtractRectFrom(const Region &region);
    void Offset(int dx, int dy);
    bool IntersectsRect(const RectBounds *bounds) const;
    bool Intersects(const Region &region) const;
    bool ContainsRect(const RectBounds *bounds) const;
    bool Contains(const Region &region) const;
    bool HasSameBoundsAs(const Region &region) const;
    RectBounds *GetRect(RectBounds *outBounds) const;

private:
    RectBounds m_bounds;
};

typedef char RegionSizeMustBe20[sizeof(Region) == 0x14 ? 1 : -1];

#endif
