// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000N2
// Source by-file doc: by-file/RectBounds.md
// UID:0000BU | by-class/RectBounds.md | Completion:95 | Confidence:94
#ifndef NEXUSTK_UI_CORE_RECTBOUNDS_H
#define NEXUSTK_UI_CORE_RECTBOUNDS_H

struct Point
{
    int y;
    int x;
};

struct RectBounds
{
    int left;
    int top;
    int right;
    int bottom;

    bool IsEmptyOrInvalid() const;
    bool HasSameSizeAs(const RectBounds *bounds) const;
    bool ContainsPoint(int y, int x) const;
    bool ContainsRect(const RectBounds *bounds) const;
    bool IntersectInto(const RectBounds *bounds, RectBounds *outBounds) const;
    void UnionInto(const RectBounds *bounds, RectBounds *outBounds) const;
    void SetLTRB(int leftValue, int topValue, int rightValue, int bottomValue);
    void Offset(int dx, int dy);
    void Inset(int dx, int dy);
    bool IntersectWith(const RectBounds *bounds);
    RectBounds *UnionWith(const RectBounds *bounds);
    void ClampWithin(int leftLimit, int topLimit,
                     int rightLimit, int bottomLimit);
    RectBounds *InsetByQuarter(RectBounds *outBounds) const;
    RectBounds *OutsetByHalf(RectBounds *outBounds) const;
};

// UID:00015S | by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md | Completion:95 | Confidence:95
void InitPointPair(Point *point, int y, int x);
void InitRectBounds(RectBounds *bounds, int left, int top, int right, int bottom);
void InitRectBoundsFromSize(RectBounds *bounds, int left, int top, int width, int height);
// UID:00015T | by-memory/0x004b7ca0-0x004b7cb6.RectArea.md | Completion:95 | Confidence:93
int RectArea(const RectBounds *bounds);
bool IntersectRects(const RectBounds *first, const RectBounds *second, RectBounds *result);
void UnionRects(const RectBounds *first, const RectBounds *second, RectBounds *result);
void OffsetRect(RectBounds *bounds, int dx, int dy);
void InsetRect(RectBounds *bounds, int dx, int dy);
bool PointInRect(int y, int x, const RectBounds *bounds);
bool IsRectEmptyOrInvalid(const RectBounds *bounds);
bool RectsEquivalent(const RectBounds *first, const RectBounds *second);
bool RectContainsRect(const RectBounds *inner, const RectBounds *outer);

#endif
