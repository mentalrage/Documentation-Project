// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IU
// Source by-file doc: by-file/DialogSession.md
// UID:00003S | by-class/DialogInSession.md | Completion:92 | Confidence:93
class DialogSession;

class DialogInSession : public DialogPane
{
public:
    DialogInSession(DialogSession *session,
                    unsigned short dialogConfigId,
                    unsigned char dialogType);
    virtual ~DialogInSession();

    unsigned char m_dialogType;
    DialogSession *m_session;
};

[[No Children Attached]]

// UID:00003U | by-class/DialogSession.md | Completion:92 | Confidence:93
class List;
class DialogInSession;

class DialogSession : public Pane
{
public:
    DialogSession();
    virtual ~DialogSession();

    void CloseAllDialogs();
    void PushDialog(DialogInSession *dialog);
    void PopCurrentDialog(bool shouldAnimate);
    DialogInSession *FindPreviousDialog(DialogInSession *dialog);
    DialogInSession *GetDialogAtIndex(int index);

private:
    void ActivateNextDialog(bool shouldAnimate);
    int FindDialogIndex(DialogInSession *dialog);

protected:
    List *m_dialogList;
    unsigned char m_activeDialogIndex;
};

[[No Children Attached]]
