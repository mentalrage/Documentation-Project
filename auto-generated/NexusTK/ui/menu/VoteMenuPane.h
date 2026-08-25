// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000P6
// Source by-file doc: by-file/VoteMenuPane.md
// UID:0000FX | by-class/VoteMenuPane.md | Completion:93 | Confidence:95
class Event;
struct EPFTileContext;
typedef EPFTileContext FrameDrawRecord;

class VoteMenuPane : public Pane
{
public:
    VoteMenuPane(int voteType, const wchar_t *targetName);
    virtual ~VoteMenuPane();

protected:
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnPaint();
    virtual void DrawBackground();
    virtual void DrawBorder();

private:
    enum {
        kPromoteRow = 0,
        kDemoteRow = 1,
        kNoVoteRow = -1
    };

    bool m_voteRowPressed;
    signed char m_highlightedVoteRow;
    int m_voteType;
    wchar_t m_targetName[0x21];
};

extern VoteMenuPane *g_pVoteMenuPane;
