// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000L0
// Source by-file doc: by-file/MainMenuPane.md
// UID:00007O | by-class/MainMenuPane.md | Completion:92 | Confidence:94
#pragma once

#include "../render/EPFTileContext.h"
#include "../render/Palette.h"
#include "../ui/core/Pane.h"
#include "../util/Singleton.h"

class Event;

class MainMenuPane : public Pane, public Singleton<MainMenuPane>
{
public:
    explicit MainMenuPane(bool fromTerminalTransition);
    virtual ~MainMenuPane();

    void SetServerName(const wchar_t *serverName);
    void SetPaintSuppressed(bool suppressed);
    void ActivateMenuItem();
    void InitializeMainUiGraph();

    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual bool HandleSystemOrControlEvent(Event *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnPaint();

    bool m_paintSuppressed;
    signed char m_menuItemCount;
    signed char m_selectedMenuItemIndex;
    wchar_t m_serverName[128];
    EPFTileContext m_backgroundTileContext;
    DLPalette m_backgroundPalette;
    bool m_fromTerminalTransition;
};

// UID:0000RF | by-global/g_pMainMenuPane.md | Completion:92 | Confidence:94
extern MainMenuPane *g_pMainMenuPane;
