// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000N3
// Source by-file doc: by-file/Region.md
// UID:0000BV | by-class/Region.md | Completion:94 | Confidence:94
#include "Region.h"

// UID:0002OP | by-memory/0x00622f54-0x00622f64.RegionVtableData.md | Completion:92 | Confidence:94
// Region RTTI and primary vtable data are compiler-generated from the
// Region class declaration emitted by [UID:0000BV][Region](by-class/Region.md); do not hand-emit this table.

// UID:0001YL | by-type/by-vtable/RegionVtable.md | Completion:92 | Confidence:94
// The Region primary vtable is compiler-generated from the virtual Region
// declaration emitted by [UID:0000BV][Region](by-class/Region.md); do not reproduce compiler table data.

// UID:0001FW | by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md | Completion:94 | Confidence:94
Region::Region()
{
    InitRectBounds(&m_bounds, 0, 0, 0, 0);
}

Region::~Region()
{
}

bool Region::IsEmpty() const
{
    return IsRectEmptyOrInvalid(&m_bounds);
}

void Region::SetEmpty()
{
    InitRectBounds(&m_bounds, 0, 0, 0, 0);
}

void Region::SetRect(const RectBounds *bounds)
{
    if (IsRectEmptyOrInvalid(bounds))
    {
        SetEmpty();
        return;
    }

    m_bounds = *bounds;
}

void Region::CopyRectFrom(const Region &region)
{
    if (IsRectEmptyOrInvalid(&region.m_bounds))
    {
        SetEmpty();
        return;
    }

    m_bounds = region.m_bounds;
}

bool Region::IntersectWith(const Region &region)
{
    RectBounds bounds = region.m_bounds;
    return IntersectRects(&bounds, &m_bounds, &m_bounds);
}

bool Region::IntersectWithRect(const RectBounds *bounds)
{
    return IntersectRects(bounds, &m_bounds, &m_bounds);
}

void Region::UnionWithRect(const RectBounds *bounds)
{
    UnionRects(bounds, &m_bounds, &m_bounds);
}

void Region::UnionWith(const Region &region)
{
    RectBounds bounds = region.m_bounds;
    UnionRects(&bounds, &m_bounds, &m_bounds);
}

void Region::SubtractRect(const RectBounds *bounds)
{
    if (bounds->top > m_bounds.top || m_bounds.bottom > bounds->bottom)
    {
        if (bounds->left <= m_bounds.left && m_bounds.right <= bounds->right)
        {
            if (bounds->top > m_bounds.top)
            {
                if (m_bounds.bottom <= bounds->bottom)
                    m_bounds.bottom = bounds->top - 1;
            }
            else if (m_bounds.bottom <= bounds->bottom)
            {
                SetEmpty();
            }
            else
            {
                m_bounds.top = bounds->bottom + 1;
            }
        }
    }
    else if (bounds->left <= m_bounds.left)
    {
        if (m_bounds.right > bounds->right)
            m_bounds.left = bounds->right + 1;
        else
            SetEmpty();
    }
    else if (m_bounds.right <= bounds->right)
    {
        m_bounds.right = bounds->left - 1;
    }

    if (IsRectEmptyOrInvalid(&m_bounds))
        SetEmpty();
}

void Region::SubtractRectFrom(const Region &region)
{
    RectBounds bounds = region.m_bounds;

    if (bounds.top > m_bounds.top || m_bounds.bottom > bounds.bottom)
    {
        if (bounds.left <= m_bounds.left && m_bounds.right <= bounds.right)
        {
            if (bounds.top > m_bounds.top)
            {
                if (m_bounds.bottom <= bounds.bottom)
                    m_bounds.bottom = bounds.top - 1;
            }
            else if (m_bounds.bottom <= bounds.bottom)
            {
                SetEmpty();
            }
            else
            {
                m_bounds.top = bounds.bottom + 1;
            }
        }
    }
    else if (bounds.left <= m_bounds.left)
    {
        if (m_bounds.right > bounds.right)
            m_bounds.left = bounds.right + 1;
        else
            SetEmpty();
    }
    else if (m_bounds.right <= bounds.right)
    {
        m_bounds.right = bounds.left - 1;
    }

    if (IsRectEmptyOrInvalid(&m_bounds))
        SetEmpty();
}

void Region::Offset(int dx, int dy)
{
    if (!IsEmpty())
        OffsetRect(&m_bounds, dx, dy);
}

bool Region::IntersectsRect(const RectBounds *bounds) const
{
    return IntersectRects(&m_bounds, bounds, NULL);
}

// UID:00042Q | by-memory/0x00554a20-0x00554a3c.MotionIntersectsRaw.md | Completion:92 | Confidence:93
bool Region::Intersects(const Region &region) const
{
    return IntersectRects(&m_bounds, &region.m_bounds, NULL);
}

// UID:00042R | by-memory/0x00554a40-0x00554a56.MotionContainsRectRaw.md | Completion:92 | Confidence:93
bool Region::ContainsRect(const RectBounds *bounds) const
{
    return RectContainsRect(bounds, &m_bounds);
}

// UID:00042S | by-memory/0x00554a60-0x00554a9b.MotionContains.md | Completion:93 | Confidence:94
bool Region::Contains(const Region &region) const
{
    RectBounds bounds = region.m_bounds;
    return RectContainsRect(&bounds, &m_bounds);
}

// UID:00042T | by-memory/0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw.md | Completion:92 | Confidence:93
bool Region::HasSameBoundsAs(const Region &region) const
{
    RectBounds bounds = region.m_bounds;
    return RectsEquivalent(&bounds, &m_bounds);
}

RectBounds *Region::GetRect(RectBounds *outBounds) const
{
    *outBounds = m_bounds;
    return outBounds;
}
