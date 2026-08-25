// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LN
// Source by-file doc: by-file/MusicControlDialog.md
// UID:00008U | by-class/MusicControlDialog.md | Completion:93 | Confidence:95
#include "DialogPane.h"
#include "StringBase.h"

class Event;

typedef mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > StringBaseW;

class MusicControlDialog : public DialogPane
{
public:
    MusicControlDialog();

    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void UpdateActionButton();
    virtual bool HandlePacketEvent(Event *event);
    virtual bool HandleType19Event(Event *event);

private:
    void FolderPathSelected(StringBaseW path);
    void PopulateCdDrivePopup();
    void ApplyPlaybackState();
    void TogglePauseState();
    void ApplySoundFrequencySelection(int selection);

    bool m_musicPaused;
};

[[No Children Attached]]
