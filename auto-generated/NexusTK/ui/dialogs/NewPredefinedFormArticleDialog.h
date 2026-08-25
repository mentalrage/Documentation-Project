// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LT
// Source by-file doc: by-file/NewPredefinedFormArticleDialog.md
// UID:000098 | by-class/NewPredefinedFormArticleDialog.md | Completion:94 | Confidence:94
#pragma once

#include "BulletinDialog.h"

class DialogSession;
struct RectBounds;

struct PredefinedFormArticleEntry
{
    unsigned char titleLength;
    wchar_t title[256];
    bool usesUserImagePane;
    unsigned char textLineCount;
    unsigned char bodyLength;
    wchar_t body[256];
    int rowAdvanceMode;
};

class NewPredefinedFormArticleDialog : public BulletinDialog
{
public:
    NewPredefinedFormArticleDialog(DialogSession *session,
        const wchar_t *previousSubject,
        RectBounds *bounds,
        const unsigned char *formPacket);

    virtual void OnPaint();
    virtual void OnCommand(int commandId, int commandParam);
    virtual void SetHoverControl(int controlId);
    virtual bool HandleTransferReplyPredefinedAlert(
        const unsigned char *packet);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    void NavigateToPreviousArticleSelection();
    bool HandleTransferReplyPredefinedAlertPayload(
        const unsigned char *payload);
    void SubmitArticle(unsigned short boardId);

    unsigned short m_predefinedFormEntryCount;
    unsigned short m_visibleFormRowCount;
    PredefinedFormArticleEntry m_predefinedFormEntries[20];
};
