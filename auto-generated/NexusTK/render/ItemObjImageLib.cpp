// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KH
// Source by-file doc: by-file/ItemObjImageLib.md
// UID:0000RA | by-global/g_pItemObjImageLib.md | Completion:92 | Confidence:94
#include "EPFTileContext.h"
#include "ImageLib.h"
#include "Surface.h"

class ItemObjImageLib;

ItemObjImageLib *g_pItemObjImageLib = 0;

// UID:00006W | by-class/ItemObjImageLib.md | Completion:93 | Confidence:94
#include "ItemObjImageLib.h"

// Exact method bodies remain on the ordered child pages.
// UID:0001UU | by-type/by-struct/ItemObjImageLibLayout.md | Completion:92 | Confidence:94
// The complete class declaration is header-owned below; no duplicate CPP-local class is emitted.

// UID:0002SD | by-memory/0x004dec30-0x004dee1b.ItemObjImageLibConstructor.md | Completion:92 | Confidence:94
ItemObjImageLib::ItemObjImageLib()
    : Singleton<ItemObjImageLib>()
{
    m_itemInfos.m_count = 0;
    m_itemInfos.m_entries = 0;
    m_itemInfos.m_defaultCapacity = 10;

    m_itemInfos.m_defaultEntry.itemTableId = -1;
    m_itemInfos.m_defaultEntry.paletteSlot = -1;
    m_itemInfos.m_defaultEntry.alpha = 0.0f;
    m_itemInfos.m_defaultEntry.lightImageIndex = -1;
    m_itemInfos.m_defaultEntry.allowPaletteFilter = false;

    DATFile itemTable;
    itemTable.Open(g_useEpfAssets ? L"ITEM.TBL" : L"ITEM.TBD");

    int itemCount = 0;
    ReadEncodedTableInt(&itemTable, &itemCount);

    if (itemCount > 0 && m_itemInfos.m_count != itemCount) {
        ItemInfo *newEntries =
            static_cast<ItemInfo *>(operator new(sizeof(ItemInfo) * itemCount));

        if (m_itemInfos.m_entries != 0) {
            int copyCount = itemCount;
            if (m_itemInfos.m_count < copyCount)
                copyCount = m_itemInfos.m_count;

            memmove(newEntries, m_itemInfos.m_entries, sizeof(ItemInfo) * copyCount);
            free(m_itemInfos.m_entries);
        }

        m_itemInfos.m_count = itemCount;
        m_itemInfos.m_entries = newEntries;
    }

    for (int index = 0; index < itemCount; ++index) {
        ItemInfo itemInfo;
        ReadEncodedTableInt(&itemTable, &itemInfo.itemTableId);
        ReadEncodedTableInt(&itemTable, &itemInfo.paletteSlot);
        ReadEncodedTableFloat(&itemTable, &itemInfo.alpha);
        ReadEncodedTableInt(&itemTable, &itemInfo.lightImageIndex);

        int allowPaletteFilter = 0;
        ReadEncodedTableInt(&itemTable, &allowPaletteFilter);
        itemInfo.allowPaletteFilter = allowPaletteFilter != 0;

        ItemInfo *slot = &m_itemInfos.m_defaultEntry;
        if (index >= 0 && index < m_itemInfos.m_count)
            slot = &m_itemInfos.m_entries[index];

        *slot = itemInfo;
    }
}

// UID:0003ND | by-memory/0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md | Completion:90 | Confidence:92
void ItemObjImageLib::RefreshItemFrameAvailability()
{
    const wchar_t *resourceName = g_useEpfAssets ? L"ITEM.EPF" : L"ITEM.EPD";

    for (int itemIndex = 0; itemIndex < m_itemInfos.m_count; ++itemIndex) {
        EPFTileContext tileContext;

        if (g_pEPFLib->LookupLayoutEntry(resourceName, itemIndex, &tileContext) == 0)
            continue;

        DLPalette *palette = g_pPaletteLib->GetSlotPalette(
            10,
            m_itemInfos.GetAtOrDefault(itemIndex)->paletteSlot,
            0);

        m_itemInfos.GetAtOrDefault(itemIndex)->allowPaletteFilter =
            tileContext.ContainsIndexedPixelInRanges(palette);
    }
}

// UID:00017O | by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md | Completion:92 | Confidence:94
ItemObjImageLib::~ItemObjImageLib()
{
}


// UID:00041S | by-memory/0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md | Completion:92 | Confidence:94
void ItemObjImageLib::DrawItemImageIn43x43Slot(
    GrafPort *drawPort,
    RectBounds *destinationBounds,
    short itemId,
    unsigned char paletteFlags,
    IntAlphaSurface *overlayMask,
    float overlayStrength)
{
    if (g_imageLibraryLoadError)
        return;

    int itemImageEntry = static_cast<unsigned short>(itemId + 0x4000);

    if (!g_useEpfAssets) {
        if (itemImageEntry >= g_currentItemImageRemapFirstEntry &&
            itemImageEntry <= g_currentItemImageRemapLastEntry) {
            itemImageEntry =
                static_cast<unsigned short>(itemImageEntry + 0xff53);
        } else if (itemImageEntry > g_legacyItemImageMaxEntry) {
            itemImageEntry = g_legacyItemImageMaxEntry;
        }
    }

    EPFTileContext tileContext;

    ItemInfo itemInfo = *m_itemInfos.GetAtOrDefault(itemImageEntry);

    if (g_pPaletteLib->GetScreenPaletteMode() == 0 ||
        itemInfo.allowPaletteFilter) {
        g_pEPFLib->LookupLayoutEntry(
            g_useEpfAssets ? L"ITEM.EPF" : L"ITEM.EPD",
            itemImageEntry,
            &tileContext);

        DLPalette *palette = g_pPaletteLib->GetSlotPalette(
            10,
            itemInfo.paletteSlot,
            paletteFlags >> 5);

        if (tileContext.bounds.right - tileContext.bounds.left >
            destinationBounds->right - destinationBounds->left) {
            tileContext.bounds.right = tileContext.bounds.left + 43;
        }

        if (tileContext.bounds.bottom - tileContext.bounds.top >
            destinationBounds->bottom - destinationBounds->top) {
            tileContext.bounds.bottom = tileContext.bounds.top + 43;
        }

        int centeredLeft =
            (destinationBounds->left + destinationBounds->right -
             tileContext.bounds.right + tileContext.bounds.left) / 2;
        int centeredTop =
            (destinationBounds->top + destinationBounds->bottom -
             tileContext.bounds.bottom + tileContext.bounds.top) / 2;

        destinationBounds->left = centeredLeft;
        destinationBounds->top = centeredTop;
        destinationBounds->right = centeredLeft + 43;
        destinationBounds->bottom = centeredTop + 43;

        SurfaceSpriteBlitOptions options;
        const SurfaceSpriteBlitOptions *blitOptions = 0;

        if (itemInfo.alpha > 0.0f) {
            options.alpha = itemInfo.alpha;

            if (paletteFlags != 0) {
                options.kind = 3;
                options.paletteShift = paletteFlags;
            } else {
                options.kind = 1;
            }

            blitOptions = &options;
        } else if (paletteFlags != 0) {
            options.kind = 2;
            options.paletteShift = paletteFlags;
            options.secondaryPaletteShift = 0;
            blitOptions = &options;
        }

        g_pfnBlitSprite(
            drawPort,
            &tileContext,
            &tileContext.bounds,
            destinationBounds,
            1,
            palette,
            blitOptions);
    }

    if (overlayMask != 0) {
        overlayMask->DrawEncodedAlphaFrame(
            destinationBounds,
            &tileContext,
            destinationBounds,
            destinationBounds->bottom,
            static_cast<unsigned char>(overlayStrength * 32.0f + 0.5f),
            destinationBounds->top,
            0,
            1);
    }
}



// UID:0000UQ | by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md | Completion:92 | Confidence:94
void ItemObjImageLib::GetItemGlyphBounds(
    short itemId,
    RectBounds *outBounds)
{
    const bool useEpfAssets = g_useEpfAssets;
    int itemImageEntry = static_cast<unsigned short>(itemId + 0x4000);

    if (!useEpfAssets) {
        if (itemImageEntry >= g_currentItemImageRemapFirstEntry &&
            itemImageEntry <= g_currentItemImageRemapLastEntry) {
            itemImageEntry = static_cast<unsigned short>(itemImageEntry + 0xff53);
        } else if (itemImageEntry > g_legacyItemImageMaxEntry) {
            itemImageEntry = g_legacyItemImageMaxEntry;
        }
    }

    g_pEPFLib->GetEntryRect(
        useEpfAssets ? L"ITEM.EPF" : L"ITEM.EPD",
        static_cast<unsigned short>(itemImageEntry),
        outBounds);

    OffsetRect(
        outBounds,
        g_mapTilePixelWidth / 2,
        g_mapTilePixelHeight / 2);
}


// UID:0003ZN | by-memory/0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants.md | Completion:92 | Confidence:94
namespace
{
    static short g_legacyItemImageMaxEntry = 0x0972;
    static short g_currentItemImageRemapFirstEntry = 0x0a20;
    static short g_currentItemImageRemapLastEntry = 0x0a56;
}

// UID:0001UT | by-type/by-struct/ItemInfo.md | Completion:90 | Confidence:92
struct ItemInfo
{
    int itemTableId;
    int paletteSlot;
    float alpha;
    int lightImageIndex;
    bool allowPaletteFilter;
    unsigned char reserved[3];
};

// UID:00041R | by-memory\0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md | Completion:88 | Confidence:91 | Empty Emitter Marker

// UID:00041T | by-memory\0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled.md | Completion:84 | Confidence:88 | Empty Emitter Marker

// UID:00041U | by-memory\0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md | Completion:87 | Confidence:91 | Empty Emitter Marker

// UID:0003LZ | by-memory\0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable.md | Completion:85 | Confidence:90 | Empty Emitter Marker
