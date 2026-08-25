// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NX
// Source by-file doc: by-file/SoundStatusPane.md
// UID:0000SB | by-global/g_pSoundStatusPane.md | Completion:94 | Confidence:95
class SoundStatusPane;

extern SoundStatusPane *g_pSoundStatusPane;

// UID:0000DJ | by-class/SoundStatusPane.md | Completion:94 | Confidence:95
#ifndef NEXUSTK_UI_PANELS_SOUNDSTATUSPANE_H
#define NEXUSTK_UI_PANELS_SOUNDSTATUSPANE_H

#include "../../util/Singleton.h"
#include "../core/Pane.h"

class Event;

class SoundStatusPane : public Pane,
                        public Singleton<SoundStatusPane>
{
public:
    SoundStatusPane();
    virtual ~SoundStatusPane();

    virtual void OnPaint();
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    int m_statusLeft;
    int m_statusRight;
    int m_statusTop;
    int m_statusBottom;
};

typedef char SoundStatusPaneSizeMustBe264[
    sizeof(SoundStatusPane) == 0x108 ? 1 : -1];

#endif
