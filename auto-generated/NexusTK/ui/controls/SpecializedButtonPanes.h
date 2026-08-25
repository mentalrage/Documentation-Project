// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NY
// Source by-file doc: by-file/SpecializedButtonPanes.md
// UID:00005P | by-class/GenderButtonControlPane.md | Completion:94 | Confidence:95
#pragma once

#include "ButtonControlPane.h"

class GenderButtonControlPane : public ButtonControlPane
{
public:
    GenderButtonControlPane(int genderIndex,
                            int stateFrameOffset,
                            bool selected,
                            const RectBounds &bounds)
        : ButtonControlPane(bounds),
          m_genderIndex(genderIndex),
          m_stateFrameOffset(stateFrameOffset),
          m_selected(selected)
    {
    }

    bool IsSelected() const
    {
        return m_selected;
    }

    void SetSelected(bool selected)
    {
        m_selected = selected;
        m_stateFrameOffset = selected ? 2 : 0;
        InvalidateRect(&m_visibleBounds);
    }

protected:
    virtual void OnPaint();
    virtual void SetVisualState(unsigned char visualState);

private:
    int m_genderIndex;
    int m_stateFrameOffset;
    bool m_selected;
};

// UID:0004ZV | by-memory/0x00500640-0x00500690.GenderButtonControlPaneConstructor.md | Completion:93 | Confidence:95
// Emitted code for this range is covered by [UID:00005P][GenderButtonControlPane](by-class/GenderButtonControlPane.md).

// UID:0004ZW | by-memory/0x00500690-0x00500697.GenderButtonControlPaneIsSelected.md | Completion:94 | Confidence:96
// Emitted code for this range is covered by [UID:00005P][GenderButtonControlPane](by-class/GenderButtonControlPane.md).

// UID:0004ZX | by-memory/0x005006a0-0x005006cc.GenderButtonControlPaneSetSelected.md | Completion:94 | Confidence:96
// Emitted code for this range is covered by [UID:00005P][GenderButtonControlPane](by-class/GenderButtonControlPane.md).

// UID:00003X | by-class/DirectionButtonControlPane.md | Completion:94 | Confidence:95
class DirectionButtonControlPane : public ButtonControlPane
{
public:
    DirectionButtonControlPane(int directionIndex, const RectBounds &bounds)
        : ButtonControlPane(bounds),
          m_directionIndex(directionIndex),
          m_stateFrameOffset(0)
    {
    }

protected:
    virtual void OnPaint();
    virtual void SetVisualState(unsigned char visualState);

private:
    int m_directionIndex;
    int m_stateFrameOffset;
};

// UID:00050G | by-memory/0x005007a0-0x005007e8.DirectionButtonControlPaneConstructor.md | Completion:93 | Confidence:95
// Emitted code for this range is covered by [UID:00003X][DirectionButtonControlPane](by-class/DirectionButtonControlPane.md).

// UID:000022 | by-class/CheckBoxTextControlPane.md | Completion:95 | Confidence:96
class CheckBoxTextControlPane : public ControlPane
{
public:
    CheckBoxTextControlPane(bool checked,
                            const wchar_t *label,
                            const RectBounds *bounds);
    virtual ~CheckBoxTextControlPane();

    void SetChecked(bool checked);
    bool GetChecked() const;

protected:
    virtual void OnPaint();
    virtual unsigned char HitTestPart(int x, int y);

private:
    bool m_checked;
    wchar_t m_label[256];
};

typedef char CheckBoxTextControlPaneSizeMustBe780[
    sizeof(CheckBoxTextControlPane) == 0x30c ? 1 : -1];

[[No Children Attached]]
