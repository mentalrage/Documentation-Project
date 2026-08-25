// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KG
// Source by-file doc: by-file/ItemObjectPane.md
// UID:00006V | by-class/ItemObjectPane.md | Completion:92 | Confidence:94
#include "../util/PoolAllocator.h"

class ObjectStatusBlob;

class ItemObjectPane : public ObjectPane
{
public:
    ItemObjectPane(
        int objectId,
        int mapX,
        int mapY,
        short itemId,
        unsigned char paletteFlags);
    virtual ~ItemObjectPane();

    void UpdateItemStatus(const ObjectStatusBlob *status);
    virtual void ClearOutputRects(
        RectBounds *paneBounds,
        RectBounds *objectDataBounds);
    virtual void RenderFrame(
        GrafPort *target,
        const RectBounds *bounds);

protected:
    short m_itemId;                          // +0x128
    unsigned char m_paletteFlags;            // +0x12a
};

typedef char ItemObjectPaneSizeMustBe300[
    sizeof(ItemObjectPane) == 0x12c ? 1 : -1];

// UID:0003HQ | by-memory/0x00537b40-0x00537b91.ItemObjectPaneConstructor.md | Completion:92 | Confidence:94
ItemObjectPane::ItemObjectPane(
    int objectId,
    int mapX,
    int mapY,
    short itemId,
    unsigned char paletteFlags)
    : ObjectPane(0, objectId, mapX, mapY)
{
    m_itemId = itemId;
    m_paletteFlags = paletteFlags;
}

// UID:0003HR | by-memory/0x00537ba0-0x00537bbf.ItemObjectPaneNonDeletingDestructor.md | Completion:92 | Confidence:94
ItemObjectPane::~ItemObjectPane()
{
}

// UID:0003HS | by-memory/0x00537bc0-0x00537be9.ItemObjectPaneRecordStateUpdate.md | Completion:92 | Confidence:94
void ItemObjectPane::UpdateItemStatus(const ObjectStatusBlob *status)
{
    m_itemId = status->m_appearanceId;
    m_paletteFlags = status->m_variantOrPalette;
    g_activeMapPane->UpdateObjectPaneScreenBounds(this);
}

// UID:0003HT | by-memory/0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects.md | Completion:92 | Confidence:94
void ItemObjectPane::ClearOutputRects(
    RectBounds *paneBounds,
    RectBounds *objectDataBounds)
{
    g_pItemObjImageLib->GetItemGlyphBounds(m_itemId, paneBounds);

    OffsetRect(
        paneBounds,
        -paneBounds->left,
        -paneBounds->top);

    OffsetRect(
        paneBounds,
        g_mapTilePixelWidth / 2 - paneBounds->right / 2,
        g_mapTilePixelHeight / 2 - paneBounds->bottom / 2);

    *objectDataBounds = *paneBounds;
}

// UID:0003HU | by-memory/0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame.md | Completion:92 | Confidence:94
void ItemObjectPane::RenderFrame(
    GrafPort *target,
    const RectBounds *bounds)
{
    g_pItemObjImageLib->DrawItemImage(
        target,
        bounds,
        m_itemId,
        m_paletteFlags,
        0,
        0.0f);
}

// UID:000385 | by-memory/0x0053d2e0-0x0053d377.ItemObjectPaneScalarDeletingDestructor.md | Completion:90 | Confidence:94
// Compiler-generated MSVC scalar deleting destructor for ItemObjectPane;
// covered by ItemObjectPane::~ItemObjectPane().

// UID:00034Y | by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md | Completion:90 | Confidence:94
// Compiler-emitted RTTI/vtable data for ItemObjectPane is regenerated from
// [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md) ItemObjectPane class declaration, virtual methods, destructor
// wrappers, and the [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md) ItemObjectPane.cpp source module. Do not emit
// hand-authored vtable arrays or a standalone source body for this .rdata range.

// UID:0002WS | by-memory/0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage.md | Completion:92 | Confidence:94
static PoolAllocator g_itemObjectPanePool(sizeof(ItemObjectPane), 8);







// UID:00034Z | by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md | Completion:88 | Confidence:92
// Compiler-emitted RTTI/vtable data for FlyingObjectPane is regenerated from
// [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md) FlyingObjectPane class declaration, virtual methods, destructor
// wrappers, and the [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md) ItemObjectPane.cpp source module. Do not emit
// hand-authored vtable arrays or a standalone source body for this .rdata range.

// UID:0002WT | by-memory/0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage.md | Completion:88 | Confidence:93
static PoolAllocator g_flyingObjectPanePool(0x144, 4);

// UID:000057 | by-class\FlyingObjectPane.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003HV | by-memory\0x00537cb0-0x00537d60.FlyingObjectPaneConstructor.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003HW | by-memory\0x00537d60-0x00537d7f.FlyingObjectPaneNonDeletingDestructor.md | Completion:85 | Confidence:90 | Empty Emitter Marker

// UID:0003HX | by-memory\0x00537d80-0x00537f1d.FlyingObjectPaneGetBoundingRect.md | Completion:86 | Confidence:91 | Empty Emitter Marker

// UID:0003HY | by-memory\0x00537f20-0x005380af.FlyingObjectPaneOnAnimationTick.md | Completion:86 | Confidence:91 | Empty Emitter Marker

// UID:000383 | by-memory\0x0053d1a0-0x0053d237.FlyingObjectPaneScalarDeletingDestructor.md | Completion:88 | Confidence:92 | Empty Emitter Marker
