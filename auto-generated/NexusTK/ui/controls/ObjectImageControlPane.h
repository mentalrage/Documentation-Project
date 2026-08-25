// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000M3
// Source by-file doc: by-file/ObjectImageControlPane.md
// UID:00009O | by-class/ObjectImageControlPane.md | Completion:94 | Confidence:94
#pragma once

#include "../core/ControlPane.h"
#include "../../map/ObjectStatusBlob.h"

struct Event;

class ObjectImageControlPane : public ControlPane
{
public:
    ObjectImageControlPane(const ObjectStatusBlob *objectStatus,
                           const RectBounds *bounds);
    virtual void OnPaint();

protected:
    ObjectStatusBlob m_objectStatus;
};

typedef char ObjectImageControlPaneSizeMustBe332[
    sizeof(ObjectImageControlPane) == 0x14c ? 1 : -1];

// UID:00009N | by-class/ObjectImageButtonPane.md | Completion:94 | Confidence:94
class ObjectImageButtonPane : public ObjectImageControlPane
{
public:
    ObjectImageButtonPane(const ObjectStatusBlob *objectStatus,
                          const RectBounds *bounds);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnPaint();

    void SetButtonHighlight(bool highlighted);
    bool IsButtonHighlighted() const;

protected:
    virtual unsigned char HitTestPart(int, int)
    {
        return 11;
    }

private:
    bool m_buttonHighlight;
};

typedef char ObjectImageButtonPaneSizeMustBe336[
    sizeof(ObjectImageButtonPane) == 0x150 ? 1 : -1];
