// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LD
// Source by-file doc: by-file/MidiPlayer.md
// UID:00008A | by-class/MidiPlayer.md | Completion:89 | Confidence:92
#ifndef NEXUSTK_AUDIO_MIDIPLAYER_H
#define NEXUSTK_AUDIO_MIDIPLAYER_H

#include "../util/LObject.h"

class MidiPlayer : public LObject
{
public:
    MidiPlayer();
    virtual ~MidiPlayer();

    void IncreaseMidiVolume();
    void DecreaseMidiVolume();
    int IsPlaybackEnabled() const;
    void EnableMidiPlayback();
    void DisableMidiPlayback();
    void SelectTrack(unsigned short trackId);
    void StopPlayback();

private:
    int m_playbackEnabled;
    int m_selectedTrackId;
};

typedef char MidiPlayerSizeMustBe12[
    sizeof(MidiPlayer) == 0x0c ? 1 : -1];

#endif

// UID:0000RM | by-global/g_pMidiPlayer.md | Completion:89 | Confidence:92
class MidiPlayer;

extern MidiPlayer *g_pMidiPlayer;
