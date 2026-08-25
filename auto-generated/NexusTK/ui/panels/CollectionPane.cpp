// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IC
// Source by-file doc: by-file/CollectionPane.md
// UID:00002X | by-class/CollectionPane.md | Completion:94 | Confidence:94
#include "CollectionPane.h"
#include "ScrollCollectionPane.h"
#include "UserPane.h"
#include "../core/Event.h"

#include "../../config/Config.h"
#include "../../metadata/MetaMan.h"
#include "../../metadata/MetaTable.h"
#include "../../render/ImageLib.h"
#include "../../render/PaletteLib.h"
#include "../../render/Surface.h"

#include <cwchar>
#include <stdlib.h>

// UID:0003Y6 | by-memory/0x0056edc0-0x0056f655.CollectionPaneOnPaint.md | Completion:92 | Confidence:94
void CollectionPane::OnPaint()
{
    EPFTileContext tileContext;

    SimpleUString groupName;
    wchar_t groupKeyText[128];
    wchar_t valueText[128];

    DLPalette *inventoryPalette =
        g_pPaletteLib->GetPaletteByName(L"ITEMINV.PAL");
    g_pEPFLib->LookupLayoutEntry(L"CLTINV.EPF", 0, &tileContext);
    g_pfnBlitSprite(this, &tileContext, &tileContext.bounds,
                    &m_visibleBounds, 0, inventoryPalette, 0);

    SetDrawMode(1);
    RectBounds rowBounds = { 6, 14, 161, 62 };
    SetTextBackColor(0);

    CollectionPlayerDataView &collectionData =
        g_pUserPane->GetCollectionData();

    int firstGroup = static_cast<int>(m_groupCountSnapshot) - 5;
    if (static_cast<int>(m_firstVisibleGroup) + 5 <=
        static_cast<int>(m_groupCountSnapshot))
        firstGroup = m_firstVisibleGroup;
    if (firstGroup < 0)
        firstGroup = 0;

    for (int visibleRow = 0, groupIndex = firstGroup;
         visibleRow < 5 && groupIndex < collectionData.groupCount;
         ++visibleRow, ++groupIndex) {
        const CollectionGroupRecord &group =
            collectionData.groups[groupIndex];
        RectBounds textBounds = rowBounds;
        const int completionPercent =
            100 * group.collectedEntries / group.totalEntries;

        g_pEPFLib->LookupLayoutEntry(
            L"CLTLIST.EPF", completionPercent / 100, &tileContext);
        RenderTileFrame(&tileContext, &tileContext.bounds, &rowBounds,
                        0, L"CLTLIST.PAL", 0);

        textBounds.left = rowBounds.left + 55;
        textBounds.right = rowBounds.left + 155;
        textBounds.top = rowBounds.top + 6;
        textBounds.bottom = rowBounds.top + 20;
        swprintf_s(groupKeyText, 128, L"%d", group.groupType);

        SimpleUString key;
        key.Assign(groupKeyText,
                   static_cast<unsigned int>(wcslen(groupKeyText)));
        SimpleUString tableName;
        tableName.Assign(L"GroupNames", 10);
        const SimpleUString *groupNameEntry =
            g_pMetaMan->FindEntry(&tableName, &key, 0);
        if (&groupName != groupNameEntry) {
            const wchar_t *entryText = groupNameEntry->Data();
            groupName.Assign(
                entryText,
                groupNameEntry->Length());
        }
        if (groupName.Data()[0] == L'\0')
            groupName.Assign(L"\xC548\xB098\xC640", 3);

        const wchar_t *groupNameText = groupName.Data();
        const int groupNameLength = static_cast<int>(wcslen(groupNameText));
        SetTextColor(0x80);
        textBounds.Offset(-1, -1);
        if (completionPercent == 100) {
            for (int pass = 0; pass < 3; ++pass) {
                for (int edge = 0; edge < 4; ++edge) {
                    DrawTextInRect(groupNameText, groupNameLength,
                                   &textBounds);
                    textBounds.Offset(0, 1);
                }
                textBounds.Offset(1, -4);
            }
        }

        textBounds.left = rowBounds.left + 55;
        textBounds.right = rowBounds.left + 155;
        textBounds.top = rowBounds.top + 6;
        textBounds.bottom = rowBounds.top + 20;
        SetTextColor(0x8f);
        DrawTextInRect(groupNameText, groupNameLength, &textBounds);
        textBounds.Offset(1, 0);
        SetTextColor(0x8f);
        DrawTextInRect(groupNameText, groupNameLength, &textBounds);

        textBounds.left = rowBounds.left + 55;
        textBounds.right = rowBounds.left + 155;
        textBounds.top = rowBounds.top + 30;
        textBounds.bottom = rowBounds.top + 44;
        swprintf_s(valueText, 128, L"%d %%", completionPercent);
        SetTextColor(0x8f);
        DrawTextInRect(valueText, wcslen(valueText), &textBounds);
        if (completionPercent == 100) {
            SetTextColor(0x0e);
            DrawTextInRect(valueText, wcslen(valueText), &textBounds);
            textBounds.Offset(1, 0);
            DrawTextInRect(valueText, wcslen(valueText), &textBounds);
            textBounds.Offset(-1, 0);
        }

        swprintf_s(valueText, 128, L"%d/%d",
                   group.collectedEntries, group.totalEntries);
        SetTextColor(0x8f);
        textBounds.left = textBounds.right -
            6 * (static_cast<int>(wcslen(valueText)) + 2);
        DrawTextInRect(valueText, wcslen(valueText), &textBounds);
        if (completionPercent == 100) {
            SetTextColor(0x25);
            DrawTextInRect(valueText, wcslen(valueText), &textBounds);
            textBounds.Offset(1, 0);
            DrawTextInRect(valueText, wcslen(valueText), &textBounds);
            textBounds.Offset(-1, 0);
        }

        rowBounds.top += 50;
        rowBounds.bottom += 50;
    }
}

// UID:0003FA | by-memory/0x00624c10-0x00624c20.CollectionPaneRectConstant.md | Completion:94 | Confidence:95
// Covered by CollectionPane::OnPaint() local rowBounds aggregate initializer:
// RectBounds rowBounds = { 6, 14, 161, 62 };



// UID:0003Y3 | by-memory/0x0056ea30-0x0056ec44.CollectionPaneInitializeCollectionData.md | Completion:93 | Confidence:94
void CollectionPane::OnActivate(const unsigned char *packetData)
{
    CollectionPlayerDataView &collectionData =
        g_pUserPane->GetCollectionData();

    if (collectionData.metadataLoaded) {
        UpdateScrollRange();
        InvalidateRect(&m_visibleBounds);
        return;
    }

    {
        SimpleUString tableName;
        tableName.Assign(L"Collections", 11);
        m_collectionsTable = g_pMetaMan->FindTableByName(&tableName);
    }
    if (m_collectionsTable && !m_collectionsTable->IsMaterialized())
        m_collectionsTable->MaterializeRowsIfNeeded(L"Collections");

    {
        SimpleUString tableName;
        tableName.Assign(L"GroupNames", 10);
        m_groupNamesTable = g_pMetaMan->FindTableByName(&tableName);
    }
    if (m_groupNamesTable && !m_groupNamesTable->IsMaterialized())
        m_groupNamesTable->MaterializeRowsIfNeeded(L"GroupNames");

    m_groupCount = packetData[3];
    collectionData.groupCount = static_cast<signed char>(m_groupCount);

    unsigned int packetOffset = 4;
    for (int groupIndex = 0;
         groupIndex < collectionData.groupCount;
         ++groupIndex) {
        CollectionGroupRecord &group = collectionData.groups[groupIndex];
        group.groupType = packetData[packetOffset++];
        group.collectedEntries = packetData[packetOffset++];
        LoadCollectionGroupRecords(&group);
    }

    UpdateScrollRange();
    InvalidateRect(&m_visibleBounds);
    collectionData.metadataLoaded = 1;
}

// UID:0003Y4 | by-memory/0x0056ec50-0x0056ecd8.CollectionPaneUpdateRenderRegion.md | Completion:92 | Confidence:94
void CollectionPane::UpdateRenderRegion(const RectBounds *bounds)
{
    RectBounds localBounds;
    InitRectBounds(&localBounds, 0, 0,
                   bounds->right - bounds->left,
                   bounds->bottom - bounds->top);

    RectBounds scrollBounds;
    InitRectBounds(&scrollBounds,
                   bounds->right - 20,
                   bounds->top + 27,
                   bounds->right - 7,
                   bounds->bottom - 21);
    m_scrollPane->SetBounds(&scrollBounds, 0);
    Pane::UpdateRenderRegion(bounds);
    UpdateScrollRange();
}

// UID:0003Y5 | by-memory/0x0056ece0-0x0056edb1.CollectionPaneUpdateScrollRange.md | Completion:93 | Confidence:94
void CollectionPane::UpdateScrollRange()
{
    CollectionPlayerDataView &collectionData =
        g_pUserPane->GetCollectionData();

    m_groupCountSnapshot = collectionData.groupCount;

    short maxRange =
        static_cast<short>(collectionData.groupCount - 5);
    if (maxRange < 0)
        maxRange = 0;
    else if (maxRange > 30000)
        maxRange = 30000;

    if (m_scrollPane->m_scrollRange != maxRange)
        m_scrollPane->SetMaxRange(maxRange);

    short position = m_firstVisibleGroup;
    if (position < 0)
        position = 0;

    const short lastPosition =
        static_cast<short>(collectionData.groupCount - 5);
    if (position > lastPosition)
        position = lastPosition;

    if (position < 0)
        position = 0;
    else if (position > 30000)
        position = 30000;

    if (m_scrollPane->m_scrollPosition != position)
        m_scrollPane->SetScrollPosition(position);

    m_firstVisibleGroup = static_cast<signed char>(position);
}

// UID:0003Y7 | by-memory/0x0056f660-0x0056f665.CollectionPaneFalseStubA.md | Completion:92 | Confidence:94
bool CollectionPane::HandleKeyOrTextEvent(Event *event)
{
    (void)event;
    return false;
}

// UID:0003Y8 | by-memory/0x0056f670-0x0056f7f4.CollectionPaneOnInputEvent.md | Completion:93 | Confidence:94
bool CollectionPane::HandlePointerOrMouseEvent(Event *event)
{
    if (g_pUserPane->IsInputLocked())
        return false;

    if (event->m_type == kEventMouseWheel &&
        PointInRect(event->m_payload.m_pointer.m_y,
                    event->m_payload.m_pointer.m_x,
                    &m_visibleBounds)) {
        const short oldPosition = m_scrollPane->m_scrollPosition;
        short newPosition = static_cast<short>(
            oldPosition -
            static_cast<short>(event->m_payload.m_pointer.m_detail));

        if (newPosition < 0)
            newPosition = 0;
        else if (newPosition > m_scrollPane->m_scrollRange)
            newPosition = m_scrollPane->m_scrollRange;

        if (oldPosition != newPosition) {
            m_firstVisibleGroup =
                static_cast<signed char>(newPosition);
            m_scrollPane->SetScrollPosition(newPosition);
            UpdateScrollRange();
            InvalidateRect(&m_visibleBounds);
        }
    } else if ((event->m_type == kEventLeftButtonDown &&
                !g_pConfig->m_doubleClickEnabled) ||
               (event->m_type == kEventLeftButtonDoubleClick &&
                g_pConfig->m_doubleClickEnabled)) {
        const short visibleSlot = HitTestVisibleGroupSlot(
            event->m_payload.m_pointer.m_y,
            event->m_payload.m_pointer.m_x);
        if (static_cast<unsigned short>(visibleSlot) <= 4) {
            const short groupIndex = static_cast<short>(
                m_firstVisibleGroup + visibleSlot);
            if (groupIndex >= 0 &&
                groupIndex <
                    g_pUserPane->GetCollectionData().groupCount &&
                visibleSlot != -1) {
                OpenOrRequestGroupDetail(groupIndex);
            }
        }
    }

    RectBounds scrollBounds;
    m_scrollPane->GetScreenBounds(&scrollBounds);
    event->m_payload.m_pointer.m_x -= scrollBounds.left;
    event->m_payload.m_pointer.m_y -= scrollBounds.top;

    EventHandler *scrollHandler =
        static_cast<EventHandler *>(m_scrollPane);
    const bool handled =
        scrollHandler->HandlePointerOrMouseEvent(event);

    event->m_payload.m_pointer.m_x += scrollBounds.left;
    event->m_payload.m_pointer.m_y += scrollBounds.top;
    return handled;
}

// UID:0001HE | by-memory/0x0056f800-0x0056f805.CollectionPaneFalseStub.md | Completion:90 | Confidence:93
bool CollectionPane::HandlePacketEvent(Event *event)
{
    return false;
}

// UID:0003Y9 | by-memory/0x0056f810-0x0056fa8a.CollectionPaneLoadCollectionGroupRecords.md | Completion:92 | Confidence:93
void CollectionPane::LoadCollectionGroupRecords(
    CollectionGroupRecord *group)
{
    unsigned char matchingRowCount = 0;
    const MetaTable::RowMap &rows = m_collectionsTable->Rows();

    for (MetaTable::RowMap::const_iterator row = rows.begin();
         row != rows.end(); ++row) {
        const std::vector<SimpleUString> &values = row->second;
        const int groupType = _wtol(values[0].Data());
        if (static_cast<unsigned char>(groupType) != group->groupType)
            continue;

        const int entryIndexValue = _wtol(values[1].Data());
        CollectionEntryRecord &entry =
            group->entries[static_cast<unsigned char>(entryIndexValue)];

        entry.entryName.Assign(row->first.Data(), row->first.Length());

        {
            SimpleUString tableName;
            tableName.Assign(L"Collections", 11);
            const SimpleUString *shortName =
                g_pMetaMan->FindEntry(&tableName, &entry.entryName, 2);
            entry.shortName.Assign(shortName->Data(), shortName->Length());
        }

        {
            SimpleUString tableName;
            tableName.Assign(L"Collections", 11);
            const SimpleUString *description =
                g_pMetaMan->FindEntry(&tableName, &entry.entryName, 3);
            entry.description.Assign(
                description->Data(), description->Length());
        }

        ++matchingRowCount;
    }

    group->totalEntries = matchingRowCount;
}

// UID:0003YA | by-memory/0x0056fa90-0x0056fac8.CollectionPaneOnScrollPositionChanged.md | Completion:92 | Confidence:94
void CollectionPane::OnScrollPositionChanged(
    unsigned char orientation,
    short oldPosition,
    short newPosition)
{
    (void)orientation;
    if (oldPosition == newPosition)
        return;

    m_firstVisibleGroup = static_cast<signed char>(newPosition);
    m_scrollPane->SetScrollPosition(newPosition);
    UpdateScrollRange();
    InvalidateRect(&m_visibleBounds);
}

// UID:0003YB | by-memory/0x0056fad0-0x0056fb36.CollectionPaneAttachToLayer.md | Completion:92 | Confidence:94
void CollectionPane::AddToLayer(RectBounds *bounds,
                                int order,
                                Pane *previousPane,
                                Layer *layer)
{
    Pane::AddToLayer(bounds, order, previousPane, layer);

    RectBounds scrollBounds;
    m_scrollPane->GetScreenBounds(&scrollBounds);
    m_scrollPane->AddToLayer(&scrollBounds, 0, this, layer);
    UpdateScrollRange();
}

// UID:0003YC | by-memory/0x0056fb40-0x0056fb56.CollectionPaneDetachFromLayer.md | Completion:92 | Confidence:94
void CollectionPane::RemoveFromLayer()
{
    m_scrollPane->RemoveFromLayer();
    Pane::RemoveFromLayer();
}

// UID:0003YD | by-memory/0x0056fb60-0x0056fb7a.CollectionPaneSetInvalidGroupSlotRectRaw.md | Completion:90 | Confidence:92
void CollectionPane::SetInvalidGroupSlotRect(
    unsigned short visibleSlot,
    RectBounds *outBounds)
{
    (void)visibleSlot;
    InitRectBounds(outBounds, -1, -1, -1, -1);
}

// UID:0003YE | by-memory/0x0056fb80-0x0056fbd3.CollectionPaneGetVisibleGroupSlotRectRaw.md | Completion:91 | Confidence:93
void CollectionPane::GetVisibleGroupSlotRect(
    unsigned short visibleSlot,
    RectBounds *outBounds)
{
    if (visibleSlot <= 4) {
        const int rowOffset = 50 * visibleSlot;
        InitRectBounds(outBounds, 6, rowOffset + 14,
                       161, rowOffset + 62);
    } else {
        InitRectBounds(outBounds, -1, -1, -1, -1);
    }
}

// UID:0003YF | by-memory/0x0056fbe0-0x0056fc73.CollectionPaneHitTestVisibleGroupSlot.md | Completion:92 | Confidence:94
short CollectionPane::HitTestVisibleGroupSlot(int y, int x)
{
    for (short visibleSlot = 0; visibleSlot <= 4; ++visibleSlot) {
        RectBounds bounds;
        GetVisibleGroupSlotRect(
            static_cast<unsigned short>(visibleSlot), &bounds);
        if (PointInRect(y, x, &bounds))
            return visibleSlot;
    }
    return -1;
}

// UID:0001HF | by-memory/0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail.md | Completion:91 | Confidence:92
void CollectionPane::OpenOrRequestGroupDetail(int groupIndex)
{
    constexpr int kCollectionGroupStride = 0x2604;
    constexpr int kCollectionGroupLoadedOffset = 0x3ec8;
    constexpr int kCollectionGroupVolumeOffset = 0x3ec9;

    unsigned char *collectionData =
        reinterpret_cast<unsigned char *>(g_pUserPane) +
        groupIndex * kCollectionGroupStride;

    unsigned char groupVolumeId = collectionData[kCollectionGroupVolumeOffset];

    if (collectionData[kCollectionGroupLoadedOffset] == 0) {
        unsigned char packet[5] = {};

        PacketBufferWriteUInt8(0x27, &packet[0]);
        PacketBufferWriteUInt8(0, &packet[1]);
        PacketBufferWriteUInt8(1, &packet[2]);
        PacketBufferWriteUInt8(groupVolumeId, &packet[3]);
        packet[4] = 0;

        g_packetSender->QueueAndSendPacket(packet, 4);
        return;
    }

    if (g_pCollectionDialogPane == nullptr) {
        new CollectionDialogPane(nullptr, groupVolumeId);
    }
}


// UID:00038U | by-memory/0x006245dc-0x00624668.CollectionPaneVtableData.md | Completion:94 | Confidence:95
// Compiler-covered by CollectionPane's complete virtual declaration and method bodies.
// The compiler emits the three RTTI/COL/vtable views, destructor adjustors, and table words.
// Do not hand-author vtable data or RTTI source.

// UID:00002Y | by-class/CollectionPane2.md | Completion:94 | Confidence:95
// UID:0001HG | by-memory/0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md | Completion:88 | Confidence:91
CollectionPane2::CollectionPane2()
    : PanelPane()
{
}

// UID:0001HH | by-memory/0x0056fda0-0x0056fdbf.CollectionPane2Destructor.md | Completion:90 | Confidence:92
CollectionPane2::~CollectionPane2()
{
}

// UID:0001HI | by-memory/0x0056fdc0-0x0056fdcc.CollectionPane2ForwardingThunk.md | Completion:93 | Confidence:95
void CollectionPane2::OnActivate(const unsigned char *packetData)
{
    InvalidateRect(&m_bounds);
}

// UID:0003YG | by-memory/0x0056fdd0-0x0056fe41.CollectionPane2OnPaint.md | Completion:94 | Confidence:95
void CollectionPane2::OnPaint()
{
    EPFTileContext context;

    DLPalette *palette =
        g_pPaletteLib->GetPaletteByName(L"ITEMINV.PAL");
    g_pEPFLib->LookupLayoutEntry(L"CLTINV.EPF", 0, &context);
    g_pfnBlitSprite(this, &context, &context.bounds, &m_visibleBounds,
                    0, palette, 0);
}

// UID:0003YH | by-memory/0x0056fe50-0x0056fe55.CollectionPane2FalseStubC4.md | Completion:92 | Confidence:95
bool CollectionPane2::HandleKeyOrTextEvent(Event *event)
{
    return false;
}

// UID:0003YI | by-memory/0x0056fe60-0x0056fe65.CollectionPane2FalseStubC0.md | Completion:92 | Confidence:95
bool CollectionPane2::HandlePointerOrMouseEvent(Event *event)
{
    return false;
}

// UID:0001HJ | by-memory/0x0056fe70-0x0056fe75.CollectionPane2FalseStub.md | Completion:92 | Confidence:95
bool CollectionPane2::HandlePacketEvent(Event *event)
{
    return false;
}

// UID:0003F1 | by-memory/0x00624a98-0x00624b30.CollectionPanePanelResourceStrings.md | Completion:92 | Confidence:94
// [UID:0003F1] No standalone source object is emitted for this pooled literal run.
// Its eight UTF-16 literals are reconstructed at the CollectionPane::OnActivate,
// CollectionPane::OnPaint, CollectionPane::LoadCollectionGroupRecords,
// and CollectionPane2::OnPaint use sites.

// UID:0003Y1 | by-memory\0x0056e940-0x0056e9e2.CollectionPaneConstructor.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:0003Y2 | by-memory\0x0056e9f0-0x0056ea25.CollectionPaneNonDeletingDestructor.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:00038Z | by-memory\0x00573370-0x005733d7.CollectionPaneScalarDeletingDestructor.md | Completion:86 | Confidence:91 | Empty Emitter Marker
