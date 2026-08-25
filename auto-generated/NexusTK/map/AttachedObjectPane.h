// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HJ
// Source by-file doc: by-file/AttachedObjectPane.md
// UID:00000M | by-class/AttachedObjectPane.md | Completion:91 | Confidence:93
#ifndef NEXUSTK_MAP_ATTACHEDOBJECTPANE_H
#define NEXUSTK_MAP_ATTACHEDOBJECTPANE_H

#include "ObjectPane.h"

class LivingObjectPane;
struct MapPoint;

class AttachedObjectPane : public ObjectPane
{
public:
    AttachedObjectPane(
        unsigned char objectType,
        LivingObjectPane *livingObjectPane,
        int mapY,
        int mapX);
    virtual ~AttachedObjectPane();

    LivingObjectPane *GetLivingObjectPane() const;
    int GetLivingObjectId() const;
    void SetLivingObjectPane(LivingObjectPane *pane);
    MapPoint *GetAttachedScreenPosition(MapPoint *outPoint) const;

    virtual void SetSpriteAttribute(unsigned char value);
    virtual void UpdatePosition() = 0;

private:
    LivingObjectPane *m_livingObjectPane; // 0x128
};

typedef char AttachedObjectPaneSizeMustBe300[
    sizeof(AttachedObjectPane) == 0x12c ? 1 : -1];

#endif
