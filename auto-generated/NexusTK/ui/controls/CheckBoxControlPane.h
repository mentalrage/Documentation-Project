// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000I7
// Source by-file doc: by-file/CheckBoxControlPane.md
// UID:000021 | by-class/CheckBoxControlPane.md | Completion:93 | Confidence:95
#pragma once

#include "ControlPane.h"

class Event;
struct RectBounds;

class CheckBoxControlPane : public ControlPane
{
public:
    CheckBoxControlPane(const RectBounds *bounds,
                        const wchar_t *tileName,
                        const wchar_t *paletteName,
                        short checkedFrame,
                        short uncheckedFrame);

    void SetChecked(bool checked);
    bool GetChecked() const;

protected:
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual void OnPaint();
    virtual void SetVisualState(unsigned char visualState);
    virtual unsigned char HitTestPart(int x, int y);

private:
    wchar_t m_tileName[16];
    wchar_t m_paletteName[16];
    short m_checkedFrame;
    short m_uncheckedFrame;
    bool m_checked;
};

[[No Children Attached]]
