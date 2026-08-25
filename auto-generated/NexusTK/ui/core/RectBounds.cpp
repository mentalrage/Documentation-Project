// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000N2
// Source by-file doc: by-file/RectBounds.md
// UID:0000BU | by-class/RectBounds.md | Completion:95 | Confidence:94
#include "RectBounds.h"

// UID:00022G | by-memory/0x004b7670-0x004b78c7.RectBoundsPredicateAndCombinationMethods.md | Completion:95 | Confidence:92
bool RectBounds::IsEmptyOrInvalid() const
{
    return bottom <= top || right <= left;
}

bool RectBounds::HasSameSizeAs(const RectBounds *bounds) const
{
    return right - left == bounds->right - bounds->left &&
           bottom - top == bounds->bottom - bounds->top;
}

bool RectBounds::ContainsPoint(int y, int x) const
{
    return left <= x && x < right &&
           top <= y && y < bottom;
}

bool RectBounds::ContainsRect(const RectBounds *bounds) const
{
    if (bounds->IsEmptyOrInvalid()) {
        return true;
    }

    if (IsEmptyOrInvalid()) {
        return false;
    }

    return left <= bounds->left &&
           bounds->right <= right &&
           top <= bounds->top &&
           bounds->bottom <= bottom;
}

bool RectBounds::IntersectInto(const RectBounds *bounds, RectBounds *outBounds) const
{
    if (IsEmptyOrInvalid() || bounds->IsEmptyOrInvalid()) {
        if (outBounds != 0) {
            outBounds->left = 0;
            outBounds->top = 0;
            outBounds->right = 0;
            outBounds->bottom = 0;
        }
        return false;
    }

    RectBounds result;
    result.left = (left <= bounds->left) ? bounds->left : left;
    result.top = (top <= bounds->top) ? bounds->top : top;
    result.right = (right <= bounds->right) ? right : bounds->right;
    result.bottom = (bottom <= bounds->bottom) ? bottom : bounds->bottom;

    if (result.IsEmptyOrInvalid()) {
        if (outBounds != 0) {
            outBounds->left = 0;
            outBounds->top = 0;
            outBounds->right = 0;
            outBounds->bottom = 0;
        }
        return false;
    }

    if (outBounds != 0) {
        *outBounds = result;
    }
    return true;
}

void RectBounds::UnionInto(const RectBounds *bounds, RectBounds *outBounds) const
{
    if (IsEmptyOrInvalid()) {
        *outBounds = *bounds;
        return;
    }

    if (bounds->IsEmptyOrInvalid()) {
        *outBounds = *this;
        return;
    }

    outBounds->left = (left <= bounds->left) ? left : bounds->left;
    outBounds->top = (top <= bounds->top) ? top : bounds->top;
    outBounds->right = (right <= bounds->right) ? bounds->right : right;
    outBounds->bottom = (bottom <= bounds->bottom) ? bounds->bottom : bottom;
}

// UID:00015Q | by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md | Completion:95 | Confidence:94
void RectBounds::SetLTRB(int leftValue, int topValue, int rightValue, int bottomValue)
{
    left = leftValue;
    top = topValue;
    right = rightValue;
    bottom = bottomValue;
}

void RectBounds::Offset(int dx, int dy)
{
    left += dx;
    top += dy;
    right += dx;
    bottom += dy;
}

// UID:00015R | by-memory/0x004b7910-0x004b795e.RectBoundsInset.md | Completion:95 | Confidence:94
void RectBounds::Inset(int dx, int dy)
{
    left += dx;
    right -= dx;
    top += dy;
    bottom -= dy;

    if (left > right) {
        left = right = (left + right) / 2;
    }

    if (top > bottom) {
        top = bottom = (top + bottom) / 2;
    }
}

bool RectBounds::IntersectWith(const RectBounds *bounds)
{
    if (bottom <= top || right <= left ||
        bounds->bottom <= bounds->top || bounds->right <= bounds->left) {
        left = 0;
        top = 0;
        right = 0;
        bottom = 0;
        return false;
    }

    const int newLeft = (left <= bounds->left) ? bounds->left : left;
    const int newTop = (top <= bounds->top) ? bounds->top : top;
    const int newRight = (right <= bounds->right) ? right : bounds->right;
    const int newBottom = (bottom <= bounds->bottom) ? bottom : bounds->bottom;

    if (newBottom <= newTop || newRight <= newLeft) {
        left = 0;
        top = 0;
        right = 0;
        bottom = 0;
        return false;
    }

    left = newLeft;
    top = newTop;
    right = newRight;
    bottom = newBottom;
    return true;
}

RectBounds *RectBounds::UnionWith(const RectBounds *bounds)
{
    if (IsEmptyOrInvalid()) {
        *this = *bounds;
        return this;
    }

    if (!bounds->IsEmptyOrInvalid()) {
        if (bounds->top < top) {
            top = bounds->top;
        }
        if (bounds->left < left) {
            left = bounds->left;
        }
        if (bottom < bounds->bottom) {
            bottom = bounds->bottom;
        }
        if (right < bounds->right) {
            right = bounds->right;
        }
    }

    return this;
}

void RectBounds::ClampWithin(int leftLimit, int topLimit, int rightLimit, int bottomLimit)
{
    if (left < leftLimit) {
        right += leftLimit - left;
        left = leftLimit;
    } else if (rightLimit < right) {
        left += rightLimit - right;
        right = rightLimit;
    }

    if (top < topLimit) {
        bottom += topLimit - top;
        top = topLimit;
    } else if (bottomLimit < bottom) {
        top += bottomLimit - bottom;
        bottom = bottomLimit;
    }
}

// UID:00022H | by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md | Completion:95 | Confidence:92
RectBounds *RectBounds::InsetByQuarter(RectBounds *outBounds) const
{
    const float quarterWidth = static_cast<float>(this->right - this->left) * 0.25f;
    const float quarterHeight = static_cast<float>(this->bottom - this->top) * 0.25f;

    outBounds->left = static_cast<int>(static_cast<float>(this->left) + quarterWidth + 0.5f);
    outBounds->top = static_cast<int>(static_cast<float>(this->top) + quarterHeight + 0.5f);
    outBounds->right = static_cast<int>(static_cast<float>(this->right) - quarterWidth);
    outBounds->bottom = static_cast<int>(static_cast<float>(this->bottom) - quarterHeight);
    return outBounds;
}

RectBounds *RectBounds::OutsetByHalf(RectBounds *outBounds) const
{
    const float halfWidth = static_cast<float>(this->right - this->left) * 0.5f;
    const float halfHeight = static_cast<float>(this->bottom - this->top) * 0.5f;

    outBounds->left = static_cast<int>(static_cast<float>(this->left) - halfWidth - 0.5f);
    outBounds->top = static_cast<int>(static_cast<float>(this->top) - halfHeight - 0.5f);
    outBounds->right = static_cast<int>(static_cast<float>(this->right) + halfWidth);
    outBounds->bottom = static_cast<int>(static_cast<float>(this->bottom) + halfHeight);
    return outBounds;
}

// UID:00015S | by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md | Completion:95 | Confidence:95
void InitPointPair(Point *point, int y, int x)
{
    point->y = y;
    point->x = x;
}

void InitRectBounds(RectBounds *bounds, int left, int top, int right, int bottom)
{
    bounds->left = left;
    bounds->top = top;
    bounds->right = right;
    bounds->bottom = bottom;
}

void InitRectBoundsFromSize(RectBounds *bounds, int left, int top, int width, int height)
{
    bounds->left = left;
    bounds->top = top;
    bounds->right = left + width;
    bounds->bottom = top + height;
}

// UID:00015T | by-memory/0x004b7ca0-0x004b7cb6.RectArea.md | Completion:95 | Confidence:93
int RectArea(const RectBounds *bounds)
{
    return (bounds->right - bounds->left) * (bounds->bottom - bounds->top);
}

bool IntersectRects(const RectBounds *firstBounds, const RectBounds *secondBounds, RectBounds *outBounds)
{
    if (firstBounds->bottom <= firstBounds->top ||
        firstBounds->right <= firstBounds->left ||
        secondBounds->bottom <= secondBounds->top ||
        secondBounds->right <= secondBounds->left) {
        if (outBounds != 0) {
            InitRectBounds(outBounds, 0, 0, 0, 0);
        }
        return false;
    }

    RectBounds result;
    result.left = (firstBounds->left <= secondBounds->left) ? secondBounds->left : firstBounds->left;
    result.top = (firstBounds->top <= secondBounds->top) ? secondBounds->top : firstBounds->top;
    result.right = (firstBounds->right <= secondBounds->right) ? firstBounds->right : secondBounds->right;
    result.bottom = (firstBounds->bottom <= secondBounds->bottom) ? firstBounds->bottom : secondBounds->bottom;

    if (result.bottom <= result.top || result.right <= result.left) {
        if (outBounds != 0) {
            InitRectBounds(outBounds, 0, 0, 0, 0);
        }
        return false;
    }

    if (outBounds != 0) {
        *outBounds = result;
    }
    return true;
}

void UnionRects(const RectBounds *firstBounds, const RectBounds *secondBounds, RectBounds *outBounds)
{
    if (firstBounds->bottom <= firstBounds->top ||
        firstBounds->right <= firstBounds->left) {
        *outBounds = *secondBounds;
        return;
    }

    if (secondBounds->bottom <= secondBounds->top ||
        secondBounds->right <= secondBounds->left) {
        *outBounds = *firstBounds;
        return;
    }

    outBounds->left = (firstBounds->left <= secondBounds->left) ? firstBounds->left : secondBounds->left;
    outBounds->top = (firstBounds->top <= secondBounds->top) ? firstBounds->top : secondBounds->top;
    outBounds->right = (firstBounds->right <= secondBounds->right) ? secondBounds->right : firstBounds->right;
    outBounds->bottom = (firstBounds->bottom <= secondBounds->bottom) ? secondBounds->bottom : firstBounds->bottom;
}

void OffsetRect(RectBounds *bounds, int dx, int dy)
{
    bounds->left += dx;
    bounds->top += dy;
    bounds->right += dx;
    bounds->bottom += dy;
}

void InsetRect(RectBounds *bounds, int dx, int dy)
{
    bounds->left += dx;
    bounds->right -= dx;
    bounds->top += dy;
    bounds->bottom -= dy;

    if (bounds->left > bounds->right) {
        const int midpoint = (bounds->left + bounds->right) / 2;
        bounds->left = midpoint;
        bounds->right = midpoint;
    }

    if (bounds->top > bounds->bottom) {
        const int midpoint = (bounds->top + bounds->bottom) / 2;
        bounds->top = midpoint;
        bounds->bottom = midpoint;
    }
}

bool PointInRect(int y, int x, const RectBounds *bounds)
{
    return bounds->left <= x && x < bounds->right &&
           bounds->top <= y && y < bounds->bottom;
}

bool IsRectEmptyOrInvalid(const RectBounds *bounds)
{
    return bounds->bottom <= bounds->top || bounds->right <= bounds->left;
}

bool RectsEquivalent(const RectBounds *firstBounds, const RectBounds *secondBounds)
{
    if (IsRectEmptyOrInvalid(firstBounds) && IsRectEmptyOrInvalid(secondBounds)) {
        return true;
    }

    return firstBounds->left == secondBounds->left &&
           firstBounds->top == secondBounds->top &&
           firstBounds->right == secondBounds->right &&
           firstBounds->bottom == secondBounds->bottom;
}

bool RectContainsRect(const RectBounds *innerBounds, const RectBounds *outerBounds)
{
    if (IsRectEmptyOrInvalid(innerBounds)) {
        return true;
    }

    if (IsRectEmptyOrInvalid(outerBounds)) {
        return false;
    }

    return outerBounds->left <= innerBounds->left &&
           innerBounds->right <= outerBounds->right &&
           outerBounds->top <= innerBounds->top &&
           innerBounds->bottom <= outerBounds->bottom;
}

// UID:00022I | by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md | Completion:95 | Confidence:92
static void AdjustRectAnchorAxis(int anchor, int offset, int *firstLow, int *firstHigh, int *secondLow, int *secondHigh);

static int Transpose3x3AnchorIndex(int anchor)
{
    switch (anchor) {
    case 0:
        return 0;
    case 1:
        return 3;
    case 2:
        return 6;
    case 3:
        return 1;
    case 4:
        return 4;
    case 5:
        return 7;
    case 6:
        return 2;
    case 7:
        return 5;
    case 8:
        return 8;
    default:
        return anchor;
    }
}

static void AdjustRectPairForAnchor(const RectBounds *firstBounds, const RectBounds *secondBounds, int anchor, RectBounds *outFirstBounds, RectBounds *outSecondBounds)
{
    *outFirstBounds = *firstBounds;
    *outSecondBounds = *secondBounds;

    AdjustRectAnchorAxis(anchor, 0, &outFirstBounds->left, &outFirstBounds->right, &outSecondBounds->left, &outSecondBounds->right);

    const int transposedAnchor = Transpose3x3AnchorIndex(anchor);
    AdjustRectAnchorAxis(transposedAnchor, 0, &outFirstBounds->top, &outFirstBounds->bottom, &outSecondBounds->top, &outSecondBounds->bottom);
}

static void AdjustRectPairForAnchorWithOffsets(const RectBounds *firstBounds, const RectBounds *secondBounds, int anchor, int horizontalOffset, int verticalOffset, RectBounds *outFirstBounds, RectBounds *outSecondBounds)
{
    *outFirstBounds = *firstBounds;
    *outSecondBounds = *secondBounds;

    AdjustRectAnchorAxis(anchor, horizontalOffset, &outFirstBounds->left, &outFirstBounds->right, &outSecondBounds->left, &outSecondBounds->right);

    const int transposedAnchor = Transpose3x3AnchorIndex(anchor);
    AdjustRectAnchorAxis(transposedAnchor, verticalOffset, &outFirstBounds->top, &outFirstBounds->bottom, &outSecondBounds->top, &outSecondBounds->bottom);
}

// UID:00022L | by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md | Completion:95 | Confidence:93
static void AdjustRectAnchorAxis(int anchor, int offset, int *firstLow, int *firstHigh, int *secondLow, int *secondHigh)
{
    const int originalSecondLow = *secondLow;
    const int originalSecondHigh = *secondHigh;
    const int secondSpan = originalSecondHigh - originalSecondLow;
    const int originalFirstLow = *firstLow;
    const int firstSpan = *firstHigh - originalFirstLow;
    const int spanDelta = firstSpan - secondSpan;

    int anchorOffset;
    switch (anchor) {
    case 0:
    case 3:
    case 6:
        anchorOffset = 0;
        break;
    case 1:
    case 4:
    case 7:
        anchorOffset = spanDelta / 2;
        break;
    case 2:
    case 5:
    case 8:
        anchorOffset = spanDelta;
        break;
    default:
        return;
    }

    if (offset < anchorOffset - firstSpan) {
        *firstLow = *firstHigh;
        *secondHigh -= secondSpan;
        return;
    }

    if (spanDelta <= 0) {
        if (offset < anchorOffset) {
            *firstLow = anchorOffset + originalFirstLow - offset;
            *secondHigh += offset + spanDelta - anchorOffset;
            return;
        }

        if (offset < anchorOffset - spanDelta) {
            *secondLow = offset + originalSecondLow - anchorOffset;
            *secondHigh += offset + spanDelta - anchorOffset;
            return;
        }
    } else {
        if (offset < anchorOffset - spanDelta) {
            *firstLow = anchorOffset + originalFirstLow - offset;
            *secondHigh += offset + spanDelta - anchorOffset;
            return;
        }

        if (offset < anchorOffset) {
            *firstLow = anchorOffset + originalFirstLow - offset;
            *firstHigh += anchorOffset - spanDelta - offset;
            return;
        }
    }

    if (offset >= anchorOffset + secondSpan) {
        *secondLow = originalSecondHigh;
        *firstHigh -= firstSpan;
    } else {
        *secondLow = offset + originalSecondLow - anchorOffset;
        *firstHigh += anchorOffset - spanDelta - offset;
    }
}
