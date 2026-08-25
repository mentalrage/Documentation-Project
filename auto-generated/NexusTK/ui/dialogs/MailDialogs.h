// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KZ
// Source by-file doc: by-file/MailDialogs.md
// UID:00007L | by-class/MailListDialog.md | Completion:94 | Confidence:93
#include "BoardDialogs.h"

class BulletinSession;
class MailListPane;
struct RectBounds;

class MailListDialog : public BoardDialog {
public:
    MailListDialog(BulletinSession *session, const RectBounds &bounds,
                   const unsigned char *packet);
    virtual void OnCommand(int commandId, int controlId);
    virtual bool OnServerPacket(const unsigned char *packet);
    void SendSelectedMailReadRequest();
    void SendSelectedMailDeleteRequests();
    void RemoveMailEntryByIdAndRefresh(unsigned short mailId);
    void RemoveSelectedMailEntriesAndRefresh();
    void RequestInitialMailPage();
    void OpenBlankComposeDialog();
    void OpenReplyToSelectedMail();
    void CreateSelectedMailDeleteConfirmAlert();
    void UpdateButtonStates();
    bool ApplyMailListUpdate(const unsigned char *packet);
    bool ShowMailDeleteReplyAlert(const unsigned char *packet);

private:
    BulletinSession *m_session;
    unsigned short m_mailListId;
};

// UID:00007M | by-class/MailListPane.md | Completion:94 | Confidence:94
#include "../controls/ListPane.h"

class GrafPort;
struct RectBounds;

struct MailListEntryRow {
    unsigned short mailId;
    unsigned char unread;
    unsigned char month;
    unsigned char day;
    unsigned char reserved;
    wchar_t sender[256];
    wchar_t subject[256];
};

class MailListPane : public ListPane {
public:
    MailListPane(short height, unsigned short mailListId);
    void AddOrUpdateMailEntry(unsigned char unread, unsigned short mailId,
                              const wchar_t *sender, unsigned char month,
                              unsigned char day, const wchar_t *subject);
    void RequestSelectedMailAndMarkRead();
    void SendDeleteRequestsForSelectedMail();
    void RemoveMailEntryById(unsigned short mailId);
    void RemoveSelectedMailEntries();
    void RequestInitialMailPage();
    void RequestOlderMailIfNeeded();
    int FindMailIdIndex(unsigned short mailId) const;
    unsigned short GetMailListId() const { return m_mailListId; }
    void SetPageRequestPending(bool pending) {
        m_pageRequestPending = pending ? 1 : 0;
    }
    virtual bool OnScrollChanged(int delta);
    virtual bool OnItemSelected(unsigned int index);
    virtual int RequestSelectedMail();
    virtual void DrawEntry(GrafPort &port, unsigned int index,
                           const MailListEntryRow &row,
                           const RectBounds &bounds);

private:
    unsigned short m_mailListId;
    unsigned char m_pageRequestPending;
};

// UID:00007K | by-class/MailDialog.md | Completion:94 | Confidence:93
#pragma once
#include "BoardDialogs.h"

class BulletinSession;
struct RectBounds;

class MailDialog : public BoardDialog {
public:
    MailDialog(BulletinSession *session, const RectBounds &bounds,
               const unsigned char *packet);
    virtual void OnCommand(int commandId, int controlId);
    virtual bool OnKeyInput(const unsigned char *keyState);
    virtual bool OnMailDeleteReply(const unsigned char *packet);
    void SendDeleteCurrentMailRequest();
    void RefreshSelectedMailInList();
    void NavigateToAdjacentMail(bool forward);
    void OpenBlankComposeDialog();
    void SendReply();
    void CreateConfirmDeleteAlert();
    bool ShowMailDeleteReplyAlert(const unsigned char *packet);
    void SaveCurrentMailToFile();

private:
    BulletinSession *m_session;
    unsigned short m_mailListId;
    unsigned short m_currentMailId;
    wchar_t m_sender[256];
    wchar_t m_date[64];
    wchar_t m_subject[256];
    wchar_t m_body[16384];
};

// UID:000096 | by-class/NewMailDialog.md | Completion:94 | Confidence:93
#include "BoardDialogs.h"

class BulletinSession;
struct RectBounds;

class NewMailDialog : public BoardDialog {
public:
    NewMailDialog(BulletinSession *session, const RectBounds &bounds,
                  const wchar_t *recipient, const wchar_t *quotedText,
                  short quotedLength);
    virtual void OnCommand(int commandId, int controlId);
    virtual bool ShowSendFailureAlert(const unsigned char *packet);
    virtual void SetHoverControl(int controlId);
    virtual bool OnMailTransferReplyPacket(const unsigned char *packet);
    void RequestInitialMailPage();
    bool AppendQuotedMessage(const wchar_t *text, short length);
    bool ShowMailTransferReplyAlert(const unsigned char *packet);
    int SendMail(short commandId);

private:
    BulletinSession *m_session;
};
