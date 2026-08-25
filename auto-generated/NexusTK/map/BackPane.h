// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HO
// Source by-file doc: by-file/BackPane.md
// UID:00000S | by-class/BackPane.md | Completion:88 | Confidence:91
#ifndef NEXUSTK_MAP_BACKPANE_H
#define NEXUSTK_MAP_BACKPANE_H

#include "../ui/core/Pane.h"
#include "../render/EPFTileContext.h"

class BackPane : public Pane
{
public:
    explicit BackPane(const wchar_t *frameResourceName);
    virtual ~BackPane();

    virtual bool OnActivate(int activateCode);
    virtual void OnPaint();

    void ShowHelpFromPacket(const unsigned char *packet);
    void ShowHelpFromPacketV2(const unsigned char *packet);
    void ShowHelpFromPacketV3(const unsigned char *packet);

private:
    EPFTileContext m_frameTileContext;
    int m_frameWidth;
    int m_frameHeight;
};

// UID:00028J | by-memory/0x0067a740-0x0067a744.g_pBackPane.md | Completion:88 | Confidence:92
class BackPane;

extern BackPane *g_pBackPane;

#endif // NEXUSTK_MAP_BACKPANE_H
