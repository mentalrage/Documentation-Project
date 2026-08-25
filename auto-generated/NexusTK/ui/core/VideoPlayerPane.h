// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000P4
// Source by-file doc: by-file/VideoPlayerPane.md
// UID:0000FV | by-class/VideoPlayerPane.md | Completion:94 | Confidence:96
struct BINK;
typedef BINK *HBINK;

class VideoPlayerPane : public Pane
{
public:
    VideoPlayerPane();
    virtual ~VideoPlayerPane();

    virtual void OnChangeMessage(LObject *owner, Message *message);
    virtual void OnPaint();
    virtual void StartPlayback();
    virtual void StopPlayback();

protected:
    bool OpenBinkVideo(const void *segmentData, unsigned int segmentSize);
    virtual void OnClose() {}
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    void CloseBinkVideo();
    void SetBinkSoundEnabled(bool enabled);
    void SeekBinkFrame(unsigned int frame);

    bool m_isPlaying;
    HBINK m_binkHandle;
};
