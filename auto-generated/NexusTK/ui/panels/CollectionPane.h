// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IC
// Source by-file doc: by-file/CollectionPane.md
// UID:00002X | by-class/CollectionPane.md | Completion:94 | Confidence:94
#pragma once

#include "../core/PanelPane.h"

class Event;
class Layer;
class MetaTable;
class ScrollCollectionPane;
struct CollectionGroupRecord;

class CollectionPane : public PanelPane
{
public:
    CollectionPane();
    virtual ~CollectionPane();

    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual void AddToLayer(RectBounds *bounds, int order,
                            Pane *previousPane, Layer *layer);
    virtual void RemoveFromLayer();
    virtual void OnPaint();
    virtual void OnActivate(const unsigned char *packetData);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);

    void LoadCollectionGroupRecords(CollectionGroupRecord *group);
    void OnScrollPositionChanged(unsigned char orientation,
                                 short oldPosition, short newPosition);

private:
    void UpdateScrollRange();
    void SetInvalidGroupSlotRect(unsigned short visibleSlot,
                                 RectBounds *outBounds);
    void GetVisibleGroupSlotRect(unsigned short visibleSlot,
                                 RectBounds *outBounds);
    short HitTestVisibleGroupSlot(int y, int x);
    void OpenOrRequestGroupDetail(int groupIndex);

    int m_groupCount;
    MetaTable *m_collectionsTable;
    MetaTable *m_groupNamesTable;
    signed char m_firstVisibleGroup;
    signed char m_groupCountSnapshot;
    ScrollCollectionPane *m_scrollPane;
};

typedef char CollectionPaneSizeMustBe0x10C[
    sizeof(CollectionPane) == 0x10C ? 1 : -1];

// UID:00002Y | by-class/CollectionPane2.md | Completion:94 | Confidence:95
#include "../core/PanelPane.h"

class Event;

class CollectionPane2 : public PanelPane
{
public:
    CollectionPane2();
    virtual ~CollectionPane2();

    virtual void OnActivate(const unsigned char *packetData);
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
};

typedef char CollectionPane2SizeMustBe0xF8[
    sizeof(CollectionPane2) == 0xF8 ? 1 : -1];
