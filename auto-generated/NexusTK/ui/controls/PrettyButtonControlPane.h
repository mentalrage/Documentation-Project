// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MP
// Source by-file doc: by-file/PrettyButtonControlPane.md
// UID:0000AR | by-class/PrettyButtonControlPane.md | Completion:92 | Confidence:93
#pragma once

#include "ButtonControlPane.h"
#include "../../util/FunctionObjects.h"
#include "../../util/StringBase.h"

struct RectBounds;

class PrettyButtonControlPane : public ButtonControlPane
{
public:
    PrettyButtonControlPane(const RectBounds &bounds,
                            const wchar_t *epfResourceName,
                            const wchar_t *paletteResourceName,
                            int normalFrameId,
                            int pressedFrameId,
                            int selectedFrameId,
                            unsigned char constructorFlag);
    virtual ~PrettyButtonControlPane();

    void SetSelected(bool selected);
    void SetCallback(FunctionObject0 *callback);

protected:
    virtual void SetState(unsigned char state);
    virtual int OnPaint();
    virtual bool OnClick(unsigned int action, int x, int y);

private:
    int m_normalFrameId;
    int m_pressedFrameId;
    int m_selectedFrameId;
    bool m_selected;
    bool m_visualStateFrameActive;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > m_epfResourceName;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > m_paletteResourceName;
    FunctionObject0 *m_callback;
};

// UID:0000AS | by-class/PrettyButtonControlPane2.md | Completion:92 | Confidence:93
class PrettyButtonControlPane2 : public ButtonControlPane
{
public:
    PrettyButtonControlPane2(const RectBounds &bounds,
                             const wchar_t *epfResourceName,
                             const wchar_t *paletteResourceName,
                             int normalFrameId,
                             int pressedFrameId,
                             int selectedFrameId,
                             int disabledFrameId,
                             unsigned char constructorFlag);
    virtual ~PrettyButtonControlPane2();

    void SetSelected(bool selected);
    void SetCallback(FunctionObject0 *callback);

protected:
    virtual void SetState(unsigned char state);
    virtual int OnPaint();
    virtual bool OnClick(unsigned int action, int x, int y);

private:
    int m_normalFrameId;
    int m_pressedFrameId;
    int m_selectedFrameId;
    int m_disabledFrameId;
    bool m_selected;
    bool m_visualStateFrameActive;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > m_epfResourceName;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > m_paletteResourceName;
    FunctionObject0 *m_callback;
};
