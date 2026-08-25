// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000O4
// Source by-file doc: by-file/StartupLogoPanes.md
// UID:00007G | by-class/LogoPane.md | Completion:93 | Confidence:94
class FunctionObject0;
struct Event;

class LogoPane : public Pane
{
public:
    LogoPane(const wchar_t *logoPath, FunctionObject0 *completionCallback);
    virtual ~LogoPane();

protected:
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    void RequestAdvance();
    void MarkReadyAndScheduleAdvance();
    void AdvanceToNextScreen();
    void LoadStaticLogoFromFile(const wchar_t *logoPath);
    void AttachStaticLogoSurface();
    void QueueAdvanceToNextScreen();

    EPFTileContext m_logoTileContext;       // +0x0f8
    DLPalette m_logoPalette;                // +0x120
    bool m_advanceRequestedBeforeReady;     // +0x34c
    bool m_logoReady;                       // +0x34d
    bool m_advanceQueued;                   // +0x34e
    unsigned char m_reserved34f;
    FunctionObject0 *m_completionCallback;  // +0x350
};
