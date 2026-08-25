// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IG
// Source by-file doc: by-file/ControlPane.md
// UID:000038 | by-class/ControlPane.md | Completion:91 | Confidence:93
#pragma once

#include "Pane.h"

class Event;
struct RectBounds;

class ControlPane : public Pane
{
public:
    ControlPane(unsigned char controlType, const RectBounds *bounds);
    virtual ~ControlPane() {}
    virtual void SetVisualState(unsigned char visualState);
    virtual void Enable();
    virtual void Disable();
    bool IsEnabled() const { return m_enabled; }
    bool IsSelectable() const { return m_controlFlags != 0; }
    void SetSelectable(bool selectable)
    {
        m_controlFlags = selectable ? 1 : 0;
    }
    bool IgnoresHitTesting() const;
    virtual void SetIgnoreHitTesting(bool ignoreHitTesting);
    void SetHandlesEnterKey(bool handlesEnterKey)
    {
        m_handlesEnterKey = handlesEnterKey;
    }

protected:
    virtual void Deactivate();
    virtual void Activate();
    virtual unsigned char HitTestPart(int, int)
    {
        return 10;
    }

    short m_rangeStart;
    short m_rangeCurrent;
    short m_rangeEnd;
    unsigned char m_controlType;
    unsigned char m_controlFlags;
    bool m_handlesEnterKey;
    bool m_enabled;
    bool m_controlActive;
    unsigned char m_visualState;
    bool m_ignoreHitTesting;
};
