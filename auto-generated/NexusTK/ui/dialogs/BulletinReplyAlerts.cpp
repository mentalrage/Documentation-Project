// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HW
// Source by-file doc: by-file/BulletinReplyAlerts.md
// UID:000033 | by-class/ConfirmDeleteAlert.md | Completion:87 | Confidence:89
/*
[UID:000033] No standalone class-level C++ is emitted from this class page.
ConfirmDeleteAlert owns exact children: [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md) emits the constructor, and [UID:0002SE][0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest](by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md) emits the delete-request action. The class page remains an index/support page and must not duplicate child method bodies.
*/
// UID:0002US | by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md | Completion:88 | Confidence:91
ConfirmDeleteAlert::ConfirmDeleteAlert(Pane *layoutReference, bool multiDelete)
    : AlertPane(g_pLanguageMan->GetLocalizedString(0x40),
                layoutReference,
                L"Delete",
                L"Cancel"),
      m_multiDelete(multiDelete)
{
}

// UID:0002SE | by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md | Completion:88 | Confidence:91
// [UID:0002SE] by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md
void ConfirmDeleteAlert::SendDeleteRequest()
{
    ArticleDialog *deleteContext = static_cast<ArticleDialog *>(m_layoutReference);

    if (m_multiDelete) {
        ArticleListPane *articleList = deleteContext->GetActiveArticleList();
        int selectedIndices[256];
        int selectedCount = articleList->GetSelectedIndices(selectedIndices, 256);

        for (int i = 0; i < selectedCount; ++i) {
            const ArticleListEntryRow *row = articleList->GetItemAt(selectedIndices[i]);

            unsigned char packet[7];
            PacketBufferWriteUInt8(0x3b, packet + 0);
            PacketBufferWriteUInt8(0x05, packet + 1);
            PacketBufferWriteUInt16BE(articleList->GetBoardId(), packet + 2);
            PacketBufferWriteUInt16BE(row->articleId, packet + 4);
            packet[6] = 0;
            g_packetSender->QueueAndSendPacket(packet, 6);
        }
    } else {
        const ArticleListEntryRow *row = deleteContext->GetSelectedArticleRecord();

        unsigned char packet[7];
        PacketBufferWriteUInt8(0x3b, packet + 0);
        PacketBufferWriteUInt8(0x05, packet + 1);
        PacketBufferWriteUInt16BE(row->boardId, packet + 2);
        PacketBufferWriteUInt16BE(deleteContext->GetCurrentArticleId(), packet + 4);
        packet[6] = 0;
        g_packetSender->QueueAndSendPacket(packet, 6);
    }

    if (g_pUserPane != 0) {
        g_pUserPane->m_activeDialogHostPane = deleteContext;
    }

    CreateScreenDimmer();
}

// UID:000034 | by-class/ConfirmDeleteMailAlert.md | Completion:87 | Confidence:90
/*
[UID:000034] No standalone class-level C++ is emitted from this class page.
ConfirmDeleteMailAlert owns exact children including [UID:0002SF][0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest](by-memory/0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest.md) for the delete-request action. The class page remains an index/support page and must not duplicate child method bodies.
*/

// UID:0002SF | by-memory/0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest.md | Completion:88 | Confidence:91
// [UID:0002SF] by-memory/0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest.md
void ConfirmDeleteMailAlert::SendDeleteRequest()
{
    MailDialog *mailContext = static_cast<MailDialog *>(m_layoutReference);

    if (m_multiDelete) {
        MailListPane *mailList = mailContext->GetReplyListPane();
        int selectedIndices[256];
        int selectedCount = mailList->GetSelectedIndices(selectedIndices, 256);

        for (int i = 0; i < selectedCount; ++i) {
            const MailListEntryRow *row = mailList->GetItemAt(selectedIndices[i]);

            unsigned char packet[7];
            PacketBufferWriteUInt8(0x3b, packet + 0);
            PacketBufferWriteUInt8(0x05, packet + 1);
            PacketBufferWriteUInt16BE(mailList->GetMailType(), packet + 2);
            PacketBufferWriteUInt16BE(row->mailId, packet + 4);
            packet[6] = 0;
            g_packetSender->QueueAndSendPacket(packet, 6);
        }
    } else {
        const MailListEntryRow *row = mailContext->GetCurrentMailEntry();

        unsigned char packet[7];
        PacketBufferWriteUInt8(0x3b, packet + 0);
        PacketBufferWriteUInt8(0x05, packet + 1);
        PacketBufferWriteUInt16BE(row->mailType, packet + 2);
        PacketBufferWriteUInt16BE(mailContext->GetCurrentMailId(), packet + 4);
        packet[6] = 0;
        g_packetSender->QueueAndSendPacket(packet, 6);
    }

    if (g_pUserPane != 0) {
        g_pUserPane->m_activeDialogHostPane = mailContext;
    }

    CreateScreenDimmer();
}

// UID:00003O | by-class/DeleteReplyAlert.md | Completion:92 | Confidence:94
class DeleteReplyAlert : public AlertPane
{
public:
    DeleteReplyAlert(bool deleteSucceeded,
                     const wchar_t *messageText,
                     Pane *layoutReference,
                     bool multiDelete);
    virtual ~DeleteReplyAlert();

    static DeleteReplyAlert *GetSingleton();

protected:
    virtual void OnPrimaryButton();

private:
    bool m_multiDelete;
    bool m_deleteSucceeded;
};

// UID:0004WC | by-memory/0x0047e2f0-0x0047e34b.DeleteReplyAlertConstructor.md | Completion:93 | Confidence:95
DeleteReplyAlert::DeleteReplyAlert(bool deleteSucceeded,
                                   const wchar_t *messageText,
                                   Pane *layoutReference,
                                   bool multiDelete)
    : AlertPane(messageText, layoutReference, L"OK", 0),
      m_multiDelete(multiDelete),
      m_deleteSucceeded(deleteSucceeded)
{
    g_pDeleteReplyAlert = this;
}

// UID:0004WD | by-memory/0x0047e350-0x0047e379.DeleteReplyAlertDestructor.md | Completion:92 | Confidence:94
DeleteReplyAlert::~DeleteReplyAlert()
{
    g_pDeleteReplyAlert = 0;
}

// UID:0004WE | by-memory/0x0047e380-0x0047e386.DeleteReplyAlertGetSingleton.md | Completion:91 | Confidence:93
DeleteReplyAlert *DeleteReplyAlert::GetSingleton()
{
    return g_pDeleteReplyAlert;
}

// UID:0004WF | by-memory/0x0047e390-0x0047e4a6.DeleteReplyAlertOnPrimaryButton.md | Completion:93 | Confidence:95
void DeleteReplyAlert::OnPrimaryButton()
{
    if (!m_deleteSucceeded) {
        return;
    }

    if (m_multiDelete) {
        ArticleListDialog *listDialog =
            static_cast<ArticleListDialog *>(m_layoutReference);
        ArticleListPane *articleList = listDialog->GetArticleListPane();
        int selectedIndices[256];
        int selectedCount =
            articleList->GetSelectedIndices(selectedIndices, 256);

        for (int i = 0; i < selectedCount; ++i) {
            articleList->RemoveItems(selectedIndices[i] - i, 1);
        }

        listDialog->RefreshContents();
        return;
    }

    ArticleDialog *currentDialog =
        static_cast<ArticleDialog *>(m_layoutReference);
    DialogSession *session = currentDialog->GetDialogSession();
    ArticleListDialog *listDialog =
        static_cast<ArticleListDialog *>(
            session->FindPreviousDialog(currentDialog));
    unsigned short articleId = currentDialog->GetCurrentArticleId();
    ArticleListPane *articleList = listDialog->GetArticleListPane();

    int row = articleList->FindArticleById(articleId);
    if (row != -1) {
        articleList->RemoveItems(row, 1);
    }

    listDialog->RefreshContents();
    session->PopCurrentDialog(false);
}

// UID:00007J | by-class/MailDeleteReplyAlert.md | Completion:91 | Confidence:93
class MailDeleteReplyAlert : public AlertPane
{
public:
    MailDeleteReplyAlert(bool deleteSucceeded,
                         const wchar_t *messageText,
                         Pane *layoutReference,
                         bool deleteAllReplies);
    virtual ~MailDeleteReplyAlert();

protected:
    virtual void OnPrimaryButton();

private:
    bool m_deleteAllReplies;
};

// UID:0002T7 | by-memory/0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md | Completion:92 | Confidence:94
// [UID:0002T7] by-memory/0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md
MailDeleteReplyAlert::MailDeleteReplyAlert(bool deleteSucceeded,
                                           const wchar_t *messageText,
                                           Pane *layoutReference,
                                           bool deleteAllReplies)
    : AlertPane(messageText, layoutReference, L"OK", 0),
      m_deleteAllReplies(deleteAllReplies)
{
    g_pMailDeleteReplyAlert = this;
}

// UID:0002T8 | by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md | Completion:88 | Confidence:92
// [UID:0002T8] by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md
MailDeleteReplyAlert::~MailDeleteReplyAlert()
{
    g_pMailDeleteReplyAlert = 0;
}

MailDeleteReplyAlert *GetMailDeleteReplyAlertSingleton()
{
    return g_pMailDeleteReplyAlert;
}

// UID:0002T9 | by-memory/0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md | Completion:90 | Confidence:93
// [UID:0002T9] by-memory/0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md
void MailDeleteReplyAlert::OnPrimaryButton()
{
    MailDialog *currentDialog = static_cast<MailDialog *>(m_layoutReference);

    if (m_deleteAllReplies) {
        MailListPane *replyList = currentDialog->GetReplyListPane();
        int selectedIndices[256];
        int selectedCount = replyList->GetSelectedIndices(selectedIndices, 256);

        for (int i = 0; i < selectedCount; ++i) {
            replyList->RemoveItems(selectedIndices[i] - i, 1);
        }

        currentDialog->RefreshContents();
        return;
    }

    DialogSession *session = currentDialog->GetDialogSession();
    MailDialog *previousDialog =
        static_cast<MailDialog *>(session->FindPreviousDialog(currentDialog));
    unsigned short replyId = currentDialog->GetCurrentReplyId();
    MailListPane *replyList = previousDialog->GetReplyListPane();

    int row = replyList->FindMailIdIndex(replyId);
    if (row != -1) {
        replyList->RemoveItems(row, 1);
    }

    previousDialog->RefreshContents();
    session->PopCurrentDialog(false);
}

// UID:00007N | by-class/MailTransferReplyAlert.md | Completion:87 | Confidence:90
/*
[UID:00007N] No standalone class-level C++ is emitted from this class page.
MailTransferReplyAlert has exact raw-constructor and action evidence, but final class/source output is blocked by unresolved base/helper/resource names, source split between BulletinReplyAlerts and MailDialogs, and owner/session declarations.
*/

// UID:0000F5 | by-class/TransferReplyAlert.md | Completion:86 | Confidence:88
/*
[UID:0000F5] No standalone class-level C++ is emitted from this class page.
TransferReplyAlert owns exact child pages: [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md) emits the constructor and [UID:0002EL][0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm](by-memory/0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm.md) emits the confirm action. The class page remains an index/support page and must not duplicate child bodies.
*/
// UID:00021A | by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md | Completion:87 | Confidence:91
// [UID:00021A] by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md
TransferReplyAlert::TransferReplyAlert(bool popSessionAfterConfirm,
                                       const wchar_t *messageText,
                                       Pane *layoutReference)
    : AlertPane(messageText,
                layoutReference,
                L"OK",
                0),
      m_popSessionAfterConfirm(popSessionAfterConfirm)
{
}

// UID:0002EL | by-memory/0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm.md | Completion:88 | Confidence:91
// [UID:0002EL] by-memory/0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm.md
void TransferReplyAlert::OnConfirm()
{
    DialogPane *ownerDialog = static_cast<DialogPane *>(m_layoutReference);

    Close();

    DialogSession *session = ownerDialog->GetDialogSession();
    DialogPane *previousDialog = session->FindPreviousDialog(ownerDialog);
    ArticleListPane *articleList = previousDialog->GetArticleListPane();
    short selectedArticleId = articleList->GetSelectedArticleId();
    char modeOffset = (g_useEpfAssets == 1) ? -20 : -16;

    SendArticleNavigationRequest(selectedArticleId, 0x7fff, modeOffset);

    if (m_popSessionAfterConfirm) {
        session->PopCurrentDialog(false);
    }
}

// UID:0000F6 | by-class/TransferReplyPredefinedAlert.md | Completion:86 | Confidence:89
/*
[UID:0000F6] No standalone class-level C++ is emitted from this class page.
TransferReplyPredefinedAlert owns exact child pages: [UID:0002EM][0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor](by-memory/0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor.md) emits the constructor and [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md) emits the alert action. The class page remains an index/support page and must not duplicate child bodies; stale recovered generated-source conflict belongs in prose, not emitted code.
*/
// UID:0002EM | by-memory/0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor.md | Completion:87 | Confidence:91
// [UID:0002EM] by-memory/0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor.md
TransferReplyPredefinedAlert::TransferReplyPredefinedAlert(bool popSessionAfterConfirm,
                                                           const wchar_t *messageText,
                                                           Pane *layoutReference)
    : AlertPane(messageText,
                layoutReference,
                L"OK",
                0),
      m_popSessionAfterConfirm(popSessionAfterConfirm)
{
}

// UID:0000ZN | by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md | Completion:88 | Confidence:91
// [UID:0000ZN] by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md
void TransferReplyPredefinedAlert::OnAlertAction()
{
    DialogPane *ownerDialog = static_cast<DialogPane *>(m_layoutReference);

    Close();

    DialogSession *session = ownerDialog->GetDialogSession();
    DialogPane *previousDialog = session->FindPreviousDialog(ownerDialog);
    ArticleListPane *articleList = previousDialog->GetArticleListPane();
    short selectedArticleId = articleList->GetSelectedArticleId();
    char modeOffset = (g_useEpfAssets == 1) ? -20 : -16;

    SendArticleNavigationRequest(selectedArticleId, 0x7fff, modeOffset);

    if (m_popSessionAfterConfirm) {
        session->PopCurrentDialog(false);
    }
}

// UID:0002W3 | by-global/g_pDeleteReplyAlert.md | Completion:89 | Confidence:92
// [UID:0002W3] by-global/g_pDeleteReplyAlert.md
class DeleteReplyAlert;

DeleteReplyAlert *g_pDeleteReplyAlert = 0;

// UID:0002W5 | by-global/g_pMailDeleteReplyAlert.md | Completion:89 | Confidence:92
// [UID:0002W5] by-global/g_pMailDeleteReplyAlert.md
class MailDeleteReplyAlert;

MailDeleteReplyAlert *g_pMailDeleteReplyAlert = 0;

// UID:0003MZ | by-memory\0x0047e4b0-0x0047e508.ConfirmDeleteMailAlertRawConstructor.md | Completion:86 | Confidence:89 | Empty Emitter Marker
