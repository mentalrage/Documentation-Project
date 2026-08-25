// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000P9
// Source by-file doc: by-file/WebBoardDialog.md
// UID:0000G2 | by-class/WebBoardDialog.md | Completion:92 | Confidence:93
#include "../../browser/Browser.h"

class Event;
class InputEvent;
class ImageButtonControlPane;

class WebBoardDialog : public BrowserPane
{
public:
    WebBoardDialog(int boardMode,
                   const wchar_t *boardOwnerName,
                   const void *initialResponsePacket,
                   OLECHAR *initialUrl);
    virtual ~WebBoardDialog();

    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool OnPacket(void *event);
    virtual bool OnKeyEvent(InputEvent *event);

    void RefreshLayout(int mode);
    bool HandleBoardResponse(const void *packet);
    void SendInitialBoardRequest(unsigned char boardMode);

private:
    BrowserControlPane *m_browserControlPane; // +0x26c
    unsigned char m_reserved[8];              // +0x270
    ImageButtonControlPane *m_closeButton;    // +0x278
    wchar_t m_boardOwnerName[0x80];           // +0x27c
};

// UID:0000G3 | by-class/WebBoardDialogOld.md | Completion:92 | Confidence:93
#include "../../browser/Browser.h"

class Event;

class WebBoardDialogOld : public BrowserPane
{
public:
    WebBoardDialogOld(const unsigned char *initialResponsePayload,
                      OLECHAR *initialUrl);
    virtual ~WebBoardDialogOld();

    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool OnWebBoardPacket(void *event);

    bool HandleBoardResponse(const unsigned char *payload);
    void SendInitialBoardRequest();

private:
    BrowserControlPane *m_browserControlPane;
    unsigned char m_reserved[8];
};
