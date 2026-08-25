// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LX
// Source by-file doc: by-file/NewUserMiscDialogPane.md
// UID:00009F | by-class/NewUserMiscDialogPane.md | Completion:92 | Confidence:94
class ControlPaneEvent;
class Event;
class KeyEvent;
class NewUserMiscDialogPane;

extern NewUserMiscDialogPane *g_pNewUserMiscDialogPane;

class NewUserMiscDialogPane : public DialogPane
{
public:
    NewUserMiscDialogPane();
    virtual ~NewUserMiscDialogPane();

protected:
    virtual void HandleCommand(int commandId, int notifyCode);
    virtual bool HandlePacketEvent(Event *event);
    virtual bool OnKeyDown(KeyEvent *event);
    virtual bool ShowControlHelp(ControlPaneEvent *event);

private:
    bool HandleCreateCharacterReply(const unsigned char *packet);
};
